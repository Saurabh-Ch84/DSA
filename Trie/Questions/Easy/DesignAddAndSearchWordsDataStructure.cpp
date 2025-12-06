#include<iostream>
using namespace std;

class WordDictionary {
    class Trie {
        Trie* children[26];
        bool isEnd;
    public:
        Trie() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }

        void insert(string &word) {
            Trie* currentNode = this;
            for (char letter : word) {
                int idx = letter - 'a';
                if (!currentNode->children[idx])
                    currentNode->children[idx] = new Trie();
                currentNode = currentNode->children[idx];
            }
            currentNode->isEnd = true;
        }

        bool search(string &word,Trie* currentNode,int j,int n) {
            for(int i=j;i<n;i++){
                if(word[i]=='.'){
                    for(char ch='a';ch<='z';ch++){
                        if( currentNode->children[ch-'a'] && 
                            search(word,currentNode->children[ch-'a'],i+1,n)) 
                            return true;
                    }
                    return false;
                }
                int idx=word[i]-'a';
                if(!currentNode->children[idx]) return false;
                currentNode=currentNode->children[idx];
            }
            return currentNode->isEnd;
        }
    };
public:
    Trie *root;
    WordDictionary(){
        root=new Trie();
    }

    void addWord(string word) {
        root->insert(word);
    }

    bool search(string word){
        return root->search(word,root,0,word.length());
    }
};

class WordDictionary {
    class Trie {
        Trie* children[26];
        bool isEnd;
    public:
        Trie() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }

        void insert(string &word) {
            Trie* currentNode = this;
            for (char letter : word) {
                int idx = letter - 'a';
                if (!currentNode->children[idx])
                    currentNode->children[idx] = new Trie();
                currentNode = currentNode->children[idx];
            }
            currentNode->isEnd = true;
        }

        bool search(string &word,Trie* currentNode,int j,int n) {
            for(int i=j;i<n;i++){
                if(word[i]=='.'){
                    for(char ch='a';ch<='z';ch++){
                        word[i]=ch;
                        if(search(word,currentNode,i,n)) return true;
                        word[i]='.';
                    }
                    return false;
                }
                int idx=word[i]-'a';
                if(!currentNode->children[idx]) return false;
                currentNode=currentNode->children[idx];
            }
            return currentNode->isEnd;
        }
    };
public:
    Trie *root;
    WordDictionary(){
        root=new Trie();
    }

    void addWord(string word) {
        root->insert(word);
    }

    bool search(string word){
        return root->search(word,root,0,word.length());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(){

return 0;
}