# About
A demo of the hash table data structure in C. The program loads and unloads a 100-word dictionary into a from-scratch hash table data structure.
I also used this to load a large 140,000 word dictionary, and it works well for that. The distribution seems to be the same for the larger dictionary as the small one.

*Disclaimer*\
main.c, dictionary.h, and the makefile were written by the staff at Harvard's CS50x\
I modified some of it\
I implemented all the actual functions (everything in dictionary.c)\
The hash function is the well known fnv1a, I modified it for my use

The program loads the dictionary into the hash table and prints out a visual of what it looks like in memory.

## Compile
command 'make'\
Requires the make utility to be installed.

## Run
./main

## Output
Here's the output so you don't have to run it:

Here's how the dictionary is loaded into memory:\
\
Array of 101 node pointers created\
opening dictionary file\
Starting infinite loop to load dictionary into hash table like so:\
   create node   write a word to node   hash the word   store the node at the hashed location on the array.\
   any words that hash to the same place form a singly linked list at that location.\
   reach EOF, break loop, close file, finished.\
\
Here's what it looks like in memory:\
array[0] -> abbots -> abalones\
array[1] -> abatement\
array[2] -> abate\
array[3]\
array[4] -> abdication\
array[5] -> abbreviated\
array[6]\
array[7] -> abbey -> abased\
array[8]\
array[9] -> aargau\
array[10] -> a\
array[11] -> aaron\
array[12] -> abdicates\
array[13] -> abba\
array[14]\
array[15] -> abbey's\
array[16]\
array[17] -> aarhus\
array[18] -> aardvark\
array[19] -> abbreviations -> abandoning\
array[20] -> abac\
array[21] -> abcoulomb\
array[22]\
array[23] -> aardwolf\
array[24] -> abdias -> aalborg\
array[25]\
array[26]\
array[27]\
array[28] -> abbott -> abasements -> abalone's\
array[29] -> abbe\
array[30] -> abadan -> aardvark's\
array[31]\
array[32] -> abases\
array[33] -> aaronic\
array[34]\
array[35] -> abdomen -> abbreviate\
array[36] -> abaser\
array[37] -> abaddon\
array[38]\
array[39] -> abatements\
array[40] -> abbreviator -> abbado -> abasement -> abandonment\
array[41]\
array[42]\
array[43]\
array[44] -> aachen\
array[45]\
array[46] -> abaxial\
array[47] -> abdicable\
array[48] -> aaa\
array[49]\
array[50] -> abbasid -> abase -> abandonee -> abaca\
array[51]\
array[52] -> abater -> abashing -> abaft\
array[53] -> abashes\
array[54] -> abattoir -> abandoned\
array[55] -> abdicate\
array[56] -> abates\
array[57]\
array[58]\
array[59]\
array[60] -> abatis\
array[61] -> abdicator\
array[62] -> abampere\
array[63] -> abbacy\
array[64] -> abakan\
array[65]\
array[66]\
array[67]\
array[68] -> abatises\
array[69] -> abdicated -> aau\
array[70] -> abbot -> abandonments -> abandon\
array[71]\
array[72] -> abandons -> abactinal\
array[73] -> ab\
array[74] -> abdicating -> aback\
array[75] -> abasing -> abacuses\
array[76]\
array[77]\
array[78] -> abator\
array[79]\
array[80]\
array[81] -> abated\
array[82] -> abalone\
array[83] -> abashment -> abandoner\
array[84] -> abberations\
array[85] -> abbevillian\
array[86]\
array[87] -> abbreviating\
array[88] -> abbreviation\
array[89]\
array[90]\
array[91] -> abbeydale\
array[92] -> abbatial\
array[93]\
array[94] -> abbot's -> abbess -> abash\
array[95] -> abbeys -> abacterial\
array[96] -> aardvarks\
array[97] -> abbreviates -> abating -> abashed -> aaas\
array[98] -> abbott's\
array[99] -> abbas -> aalesund\
array[100] -> abamp -> abacus\
\
Iterating over array and freeing all nodes, done.
