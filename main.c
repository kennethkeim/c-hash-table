// demonstrates the hash table data structure in C

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
