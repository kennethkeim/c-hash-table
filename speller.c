// Implements a spell-checker

#include <ctype.h>
#include <stdio.h>
#include "dictionary.h"

// Default dictionary
#define DICTIONARY "dictionaries/large"


int main(void)
{
    // Check for correct number of args
    // if (argc != 1)
    // {
    //     printf("This program takes no command line arguments. \n");
    //     return 1;
    // }

    // Load dictionary
    // dictionary needs to be a const char *
    bool loaded = load(DICTIONARY);

    // Exit if dictionary not loaded
    if (!loaded)
    {
        printf("Could not load %s.\n", DICTIONARY);
        return 1;
    }

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
