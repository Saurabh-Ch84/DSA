#include<iostream>
using namespace std;

class WordDictionary {
    class Trie {
    public:
        Trie* children[26];
        bool isEnd;

        Trie() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }

        void insert(string word) {
            Trie* current = this;
            for (char ch : word) {
                if (!current->children[ch - 'a'])
                    current->children[ch - 'a'] = new Trie();
                current = current->children[ch - 'a'];
            }
            current->isEnd = true;
        }

        bool search(string word) {
            Trie* current = this;
            for (char ch : word) {
                if (!current->children[ch - 'a'])
                    return false;
                current = current->children[ch - 'a'];
            }
            return current->isEnd;
        }

        bool specialSearch(Trie* node, const string& word, int index) {

            if (index == word.length()) 
                return node->isEnd;

            if (word[index] == '.') 
            {
                // Try all possible characters
                for (int i = 0; i < 26; i++) 
                {
                    if (node->children[i] && specialSearch(node->children[i], word, index + 1)) 
                        return true;
                }
            }
            else 
            {
                // Normal character
                if (node->children[word[index] - 'a'])
                    return specialSearch(node->children[word[index] - 'a'], word,index + 1);
            }
            return false;
        }
    };

public:
    Trie* t;
    WordDictionary() { t = new Trie(); }

    void addWord(string word) { t->insert(word); }

    bool search(string word) {
        if (word.find('.') == string::npos)
            return t->search(word);
        return t->specialSearch(t,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

 int main()
 {
    return 0;
 }