// Implements a dictionary's functionality

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// hashtable array
node *hashtable[ARRSIZE];

// record word count for 'size' function
unsigned int wordcount = 0;



// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // ensure word is lowercase
    char temp[LENGTH + 1];
    int i;
    for (i = 0; i < strlen(word); i++)
    {
        temp[i] = tolower(word[i]);
    }
    temp[i] = '\0';

    // hash word
    unsigned int index = fnv1a(temp);

    // search the linked list that exists at the hash location
    node *trav = hashtable[index];
    while (trav != NULL)
    {
        // compare strings
        int n = strcasecmp(trav->word, word);
        if (n == 0)
        {
            return true;
        }

        // point trav at next node if word is not found
        trav = trav->next;
    }

    return false;
}




// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // initialize hashtable array pointers to NULL
    for (int i = 0; i < ARRSIZE; i++)
    {
        hashtable[i] = NULL;
    }

    // open dictionary file
    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        return false;
    }

    // load dictionary into hash table with separate chaining
    for (;;)
    {
        // create node
        node *newnode = malloc(sizeof(node));
        if (newnode == NULL)
        {
            wordcount = 0;
            unload();
            return false;
        }
        newnode->next = NULL;

        // scan word into node
        // implementing 'fscanf' here rather than in the outer loop removes the need to scan into a temp array first.
        if (fscanf(fp, "%s", newnode->word) == EOF)
        {
            free(newnode);
            break;
        }

        // hash word
        unsigned int index = fnv1a(newnode->word);

        // store node in hash table
        newnode->next = hashtable[index];
        hashtable[index] = newnode;

        // record word count for 'size' function
        wordcount++;
    }

    fclose(fp);
    return true;
}




// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordcount;
}




// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // record number of nodes freed
    unsigned int freecount = 0;

    // free all nodes in hash table
    for (int i = 0; i < ARRSIZE; i++)
    {
        node *trav = hashtable[i];
        while (trav != NULL)
        {
            node *trav2 = trav;
            trav = trav->next;
            free(trav2);
            freecount++;
        }
    }

    // check if all nodes freed
    if (freecount < wordcount)
    {
        return false;
    }

    return true;
}
