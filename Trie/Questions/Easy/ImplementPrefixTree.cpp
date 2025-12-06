#include<iostream>
using namespace std;

class Trie {
    Trie* children[26];
    bool isEnd;
public:
    Trie() {
        isEnd=false;
        for(int i=0;i<26;i++) 
            children[i]=nullptr;
    }
    
    void insert(string word) {
        Trie* currentNode=this;
        for(char letter: word){
            int idx=letter-'a';
            if(!currentNode->children[idx])
                currentNode->children[idx]=new Trie();
            currentNode=currentNode->children[idx];
        }
        currentNode->isEnd=true;
    }
    
    bool search(string word) {
        Trie* currentNode=this;
        for(char letter: word){
            int idx=letter-'a';
            if(!currentNode->children[idx]) return false;
            currentNode=currentNode->children[idx];
        }
        return currentNode->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* currentNode=this;
        for(char letter: prefix){
            int idx=letter-'a';
            if(!currentNode->children[idx]) return false;
            currentNode=currentNode->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){

return 0;
}