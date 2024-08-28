# Compound Word Finder

This project contains a C++ program to find the longest and second-longest compound words in a list of alphabetically sorted words.

## Output
- The program will display the longest and second-longest compound words from the input files.
- The processing time for each input file will also be displayed.
- The same information will be appended to an `output.txt` file.

## Execution Steps

### Prerequisites
- You need a C++ compiler (e.g., `g++`, `clang++`) installed on your system.
- **Requirements:**
  - `Input_01.txt`
  - `Input_02.txt`

### Compilation
To compile the code, open your terminal/command prompt in the directory containing the source code and run:

```bash
g++ -o compound_word_finder compound_word_finder.cpp
```
```bash
./solution
```

### Design Decisions
#### Data Structures:

- unordered_set: Used for quick lookup of words to check if a word or its parts exist in the list.
- unordered_map: Used to store intermediate results of whether a word can be a compound word. This reduces redundant calculations and improves performance.

#### Algorithm:

The algorithm involves checking each word to determine if it can be constructed by concatenating other words from the list. This is done efficiently using recursion with memoization in the isCompoundWord function.

Words are then processed in a loop, with the longest and second-longest compound words being tracked throughout the execution within the findLongestCompoundWords function.

#### Performance Considerations
- Efficiency: The solution is designed to handle large input files efficiently by leveraging appropriate data structures (unordered_set for fast lookups and unordered_map for memoization).

- Accuracy: The use of memoization ensures that the solution is both correct and efficient, avoiding redundant calculations by ensuring that each word is checked only once.