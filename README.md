# noel

A somewhat clumsy solution to the Schwab noel problem, but it works. The final list is curated-list.txt.

### generateList.exe

This program generates a list of all possible NOEL letter combinations and saves it to all-noel-combos.txt.

* Configurations of N: N, I, Z, S
* Configurations of O: O, I
* Configurations of E: E, I, W, M
* Configurations of L: L, I, C, V, J

### findWords.exe

This program must be run from the command-line. The second argument is the library you are comparing to. For example, you would write `findWords words/filtered/scrabble.txt`. It saves the real words to matches.txt.

### words/filter.exe

This program must be run from the command-line. The second argument is the library you are filtering. I've already filtered the two word lists I found. This technically isn't necessary, but it greatly speeds up the findWords.exe program.



