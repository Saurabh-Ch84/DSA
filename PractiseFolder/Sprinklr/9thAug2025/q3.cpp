#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
    Given a set of N strings, the set is said to be a GOOD SET if no string is a prefix of another string in the set. Otherwise, it is a BAD SET. Two identical strings are also considered prefixes of each other.

You are given N strings containing only lowercase letters 'a' to 'j'.
Print GOOD SET if there is no prefix relationship.
Else print BAD SET followed by the first string which violates the condition.

Input Format:
    The first line contains an integer N — the number of strings.
    Each of the next N lines contains a string.
*/

class TrieNode
{
    bool isEnd;
    TrieNode *link[26];

public:
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            link[i] = nullptr;
        isEnd = false;
    }

    bool containsKey(char ch)
    {
        return (link[ch - 'a'] != nullptr);
    }

    TrieNode *get(char ch)
    {
        return link[ch - 'a'];
    }

    void put(char ch, TrieNode *node)
    {
        link[ch - 'a'] = node;
    }

    void setEnd()
    {
        isEnd = true;
    }

    bool isEndSet()
    {
        return isEnd;
    }

    ~TrieNode()
    {
        for (int i = 0; i < 26; ++i)
            if (link[i]) delete link[i];
    }
};

class Solution
{
    TrieNode *root;
    bool insert(string &word)
    {
        TrieNode *current = this->root;
        for (char &letter : word)
        {
            if (current->isEndSet()) // i.e., a previous string ends here so is a prefix
                return false;
            if (!current->containsKey(letter))
                current->put(letter, new TrieNode());
            current = current->get(letter);
        }
        // After inserting all characters:
        if (current->isEndSet())
            return false; // Duplicate string
        for (char ch = 'a'; ch <= 'z'; ++ch)
            if (current->containsKey(ch))
                return false; // Current word is a prefix of existing longer word
        current->setEnd();
        return true;
    }
    
    struct Comp
    {
        bool operator()(const string &a, const string &b) const{
            return a.length() < b.length();
        }
    };

public:
    Solution()
    {
        root = new TrieNode();
    }

    string isSetGoodOrNot(vector<string> &words)
    {
        // sort(words.begin(),words.end(),Comp());
        for (string &word : words)
        {
            if (!insert(word))
                return "BAD SET " + word;
        }
        return "GOOD SET";
    }
};

int main()
{
    Solution s;
    // Sample Test Case 0
    int N0 = 7;
    vector<string> test0 = {
        "aab",
        "defgab",
        "abcde",
        "aabcde",
        "bbbbbbbbbb",
        "jabjjjad"
        // The original problem had just 6 entries in its first example,
        // but you can add the exact ones from the statement
    };

    // Sample Test Case 1
    int N1 = 4;
    vector<string> test1 = {
        "aab",
        "aac",
        "aacghgh",
        "aabghgh"};

    // Sample Test Case 2
    int N2 = 3;
    vector<string> test2 = {
        "abc",
        "def",
        "ghij"};

    // Sample Test Case 3
    int N3 = 5;
    vector<string> test3 = {
        "a",
        "ab",
        "abc",
        "abcd",
        "abcde"};
    cout << s.isSetGoodOrNot(test0);
    return 0;
}