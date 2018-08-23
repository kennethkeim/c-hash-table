// Implements a spell-checker

#include <ctype.h>
#include <stdio.h>
#include "dictionary.h"

// Default dictionary
#define DICTIONARY "dictionaries/small"


int main(int argc, char *argv[])
{

   // Check for correct number of args
   if (argc != 1 && argc != 2)
   {
      printf("Usage: speller [dictionary]\n");
      return 1;
   }

   // Determine dictionary to use
   char *dictionary = (argc == 2) ? argv[1] : DICTIONARY;

   // Load dictionary
   bool loaded = load(dictionary);

   // Exit if dictionary not loaded
   if (!loaded)
   {
     printf("Could not load %s.\n", dictionary);
     return 1;
   }



   // show a visual of the dictionary in the hash table
   // show();



   // Unload dictionary
   bool unloaded = unload();

   // Abort if dictionary not unloaded
   if (!unloaded)
   {
     printf("Could not unload %s.\n", dictionary);
     return 1;
   }

   // Success
   return 0;
}
