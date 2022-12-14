## Makefile
Creates binaries `Order.cpp`, `Dictionary.cpp`, `DictionaryTest.cpp`, `DictionaryClient.cpp` (see below for file descriptions); also includes clean to remove all binaries (more specifics in Makefile)

## Dictionary.h
Header file for `Dictionary.cpp`

## Dictionary.cpp
BST implementation of a Dictionary.

Each Node in the BST has a string key and a integer value includes several helper functions to implement the functionality, as well as 2 to simply test the ADT for the assignment: `inOrderString()` and `preOrderString()`, both used to check key-value pairs and the internal structure of a Dictionary
       
## DictionaryClient.cpp
Provides test client for Dictionary functions

## DictionaryTest.cpp
Local test client for Dictionary functions

## Order.cpp
Main client file for the Dictionary ADT.  

Reads lines from input file, each line formatted to be a single (unique) string, and insert those strings as keys into a Dictionary. The corresponding values will be the line number in the input file where the string was read.  

Prints out an in-order string representation of the Dictionary (alphabetical order), and another string representation, this time in pre-order.
