# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

A pneumoconiosis caused by inhalation of very fine silicate or quartz dust. An example of the maximum length of a word.

## According to its man page, what does `getrusage` do?

Returns resource usage measures for who, which can be one of the following: RUSAGE_SELF, RUSAGE_CHILDREN, RUSAGE_THREAD.

## Per that same man page, how many members are in a variable of type `struct rusage`?

16 members. (Some members are structs containing additional members)

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

To save the time and memory that would be required to copy that data into the calculate function.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

The for loop iterates over each character in the file using 'fgetc'. If a character is alphabetical, it is appended to the
'word' array, but if an alphabetical string becomes longer than 'LENGTH', 'fgetc' skips over the rest of that alphabetical
string, and 'index' is set to zero. (so that the next potential word will be appended to the beginning of the 'word' array)

If a character is numeric, 'fgetc' will skip over the rest of that alphanumeric string, and again, 'index' will be set to zero.

If a character is neither alphabetical or numeric, and 'index' is greater than zero, an entire word is assumed to have been
found. The word is appended by '\0', word counter updated, and the word is spell checked. If the word is misspelled, it is
printed, and index is once again set to zero.


## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

With 'fgetc', you can look at each character individually, and control exactly which types of characters (such as apostrophes)
are allowed. Also, with fscanf, you may overflow the buffer with a string that is too long.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

To optimize time and memory. If you declare a 'non-const' variable, your program might allocate space on the stack each time
the function is called.
