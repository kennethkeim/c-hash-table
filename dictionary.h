// Declares a dictionary's functionality



#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// array size
// (prime number close to dictionary word count)
#define ARRSIZE 101


// Prototypes
bool load(const char *dictionary);
bool unload(void);
unsigned int fnv1a(const char *text);
void show(void);

// node struct for words
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

#endif // DICTIONARY_H
