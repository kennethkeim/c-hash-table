// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// hashtable array
node *hashtable[ARRSIZE];

// record word count
unsigned int wordcount = 0;











// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
   // explain the process
   printf("Here's how the dictionary is loaded into memory: \n");
   printf("\n");
   printf("Array of %i node pointers created \n", ARRSIZE);
   printf("opening dictionary file \n");
   printf("Starting infinite loop to load dictionary into hash table like so: \n");
   printf("   create node   write a word to node   hash the word   store the node at the hashed location on the array. \n");
   printf("   any words that hash to the same place form a singly linked list at that location. \n");
   printf("   reach EOF, break loop, close file, finished. \n");

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

      // record word count
      wordcount++;

   }

   fclose(fp);
   return true;
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
