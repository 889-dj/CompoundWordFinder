#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;

bool isCompoundWord(const string &word, const unordered_set<string> &wordsSet, unordered_map<string, bool> &memo) {
    if (memo.find(word) != memo.end()) return memo[word];
    for (int i = 1; i < word.length(); ++i) {
        string prefix = word.substr(0, i);
        string suffix = word.substr(i);
        if (wordsSet.find(prefix) != wordsSet.end() && 
            (wordsSet.find(suffix) != wordsSet.end() || isCompoundWord(suffix, wordsSet, memo))) {
            return memo[word] = true;
        }
    }
    return memo[word] = false;
}

void findLongestCompoundWords(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    unordered_set<string> wordsSet;
    vector<string> words;
    string word;

    while (file >> word) {
        words.push_back(word);
        wordsSet.insert(word);
    }
    file.close();

    string longestWord, secondLongestWord;
    unordered_map<string, bool> memo;

    auto start = chrono::high_resolution_clock::now();

    for (const auto &word : words) {
        wordsSet.erase(word);
        if (isCompoundWord(word, wordsSet, memo)) {
            if (word.length() > longestWord.length()) {
                secondLongestWord = longestWord;
                longestWord = word;
            } else if (word.length() > secondLongestWord.length()) {
                secondLongestWord = word;
            }
        }
        wordsSet.insert(word);
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;

    cout << "Longest Compound Word: " << longestWord << endl;
    cout << "Second Longest Compound Word: " << secondLongestWord << endl;
    cout << "Time taken to process file " << filename << ": " << elapsed.count() << " milliseconds" << endl;

    ofstream outputFile("output.txt", ios_base::app);
    if (outputFile.is_open()) {
        outputFile << "Results for file: " << filename << endl;
        outputFile << "Longest Compound Word: " << longestWord << endl;
        outputFile << "Second Longest Compound Word: " << secondLongestWord << endl;
        outputFile << "Time taken to process file " << filename << ": " << elapsed.count() << " milliseconds" << endl;
        outputFile << endl; // Add a newline for better readability
        outputFile.close();
    } else {
        cerr << "Failed to open output.txt for writing" << endl;
    }

}

int main() {
    findLongestCompoundWords("Input_01.txt");
    findLongestCompoundWords("Input_02.txt");
    return 0;
}
