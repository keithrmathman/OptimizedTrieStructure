# OptimizedTrieStructure
An optimized Trie Data Structure

    CONSOLE APPLICATION : Aho Cordasick algorithm implimentation Project Overview


This is a trie data structure that I have created and optimized for general use as well as specific usage as well(crossword puzzles, video games, text predictors, etc.)



*As you know the time complexities for Lookup, Delete, Add, Creation are:* 

	FOR TRIE CREATION:

The worst-case runtime for creating a trie is a combination of m, the length of the longest key in the trie, and n, 
the total number of keys in the trie. Thus, the worst case runtime of creating a trie is O(mn).



	FOR TRIE INSERTION,LOOKUP,AND DELETION:

This depends on the number of deletions, insertions, and lookups; we can call this number m,
and of course the length of the string having one of the operations attempted,  whick we can call l,
this brings the time complexity to: O(l*m)


The purpose of this datastructure is to give the users a more efficient datastructure to use.

I did some bench mark performances to test the time performance for different numbers of words being inserted into the trie. These times were taken for the creation of the trie only, 
I did not account for search, delete, insert. More testing may be done in the future. 

**Benchmark Testing**
```
Number of words|Time to create trie
-------------------------------------
10000 words:   | 96ms 
50000 words:   | 544ms 
100000 words:  | 983ms 
200000 words:  | 2125ms
```

I compared the times to general implementations of this same data structures, and the speedup of this code was 4-5x faster. This code takes advantage of inline functions, cache alignment,
pointer arithmetic, etc.


I chose to add other potentially useful features such as getting the total number of searches, deletes, adds, and total words in trie. 

to do this, use:

```
 All Functions to retreive Trie Data:

getNumberofWordsAdded()--gets total number of words added to trie, regardless if some words were deleted from trie
getNumberofWordsDeleted()--gets total number of words deleted from trie
getNumberofwordsinTrie()-- gets total number of words currently in trie 
getNumberofWordsSearched()--gets total number of search attempts in trie 
```


These functions will give you some statistics regarding the trie usage 


More potential optimizations may be done on this program, including:

space optimization, I have approx. 8GB of ram, and  a trie size of around 250000-300000 words and greater gives me a bad_alloc exception, I added a personal handler at the beginning of the program so that 
there is an option to do something else of the user wishes(free up memory for the heap to make more space for larger trie, etc.) 




 If you find any bugs, please let me know! I'll try to fix them as soon as I can!
 -Keith R.





Aho Cordasick algorithm implimentation.cpp
    This is the main application source file.

