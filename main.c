// demonstrates the hash table data structure in C

// ===========================================================================================
// main.c, dictionary.h, and the makefile were written by the staff at Harvard's CS50x
// I modified some of it
// I implemented all the actual functions (everything in dictionary.c)
// The hash function is the well known fnv1a, I modified it for my use
// ===========================================================================================


#include <ctype.h>
#include <stdio.h>
#include "dictionary.h"

// Define dictionary
#define DICTIONARY "dictionaries/small"



int main(void)
{

   // Load dictionary
   bool loaded = load(DICTIONARY);

   // Exit if dictionary not loaded
   if (!loaded)
   {
     printf("Could not load %s.\n", DICTIONARY);
     return 1;
   }

   // show a visual of the dictionary in the hash table
   show();

   // Unload dictionary
   bool unloaded = unload();

   // Abort if dictionary not unloaded
   if (!unloaded)
   {
     printf("Could not unload %s.\n", DICTIONARY);
     return 1;
   }

   // Success
   return 0;
}
