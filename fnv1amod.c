// //////////////////////////////////////////////////////////
// fnv.h
// Copyright (c) 2011 Stephan Brumme. All rights reserved.
// see http://create.stephan-brumme.com/disclaimer.html
//

// compute FNV1a hash
// originally developed by Fowler, Noll and Vo
// http://isthe.com/chongo/tech/comp/fnv/

// This is an altered version of the FNV1a hash function.
// I'm using mod to ensure the return value does not exceed the bounds of my hashtable array.

#include <stdio.h>
#include <assert.h>

#include "dictionary.h"

// default values recommended by http://isthe.com/chongo/tech/comp/fnv/
const unsigned int Prime = 0x01000193; // 16777619
const unsigned int Seed  = 0x811C9DC5; // 2166136261

// hash a C-style string
unsigned int fnv1a(const char *text)
{
    unsigned int hash = Seed;
    assert(text);
    const unsigned char *ptr = (const unsigned char *)text;
    while (*ptr)
    {
        hash = (*ptr++ ^ hash) * Prime;
        // same as hash = fnv1a(*ptr++, hash); but much faster in debug mode
    }
    hash = hash % ARRSIZE;
    return hash;
}
