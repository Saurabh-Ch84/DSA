#include <iostream>
// #include<bits/stdc++.h>
using namespace std;

class Node {
    Node* links[26];
    bool flag;
public:
    Node() {
        for (int i = 0; i < 26; i++)
            links[i] = nullptr;
        flag = false;
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != nullptr);
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }

    ~Node() {
        for (int i = 0; i < 26; ++i) {
            if (links[i]) {
                delete links[i];
            }
        }
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node* current=this->root;
        for(char &ch:word){
            if(!current->containsKey(ch))
                current->put(ch,new Node());
            current=current->get(ch);
        }
        current->setEnd();
    }

    bool search(string &word){
        Node* current=this->root;
        for(char &ch:word){
            if(!current->containsKey(ch)) return false;
            current=current->get(ch);
        }
        return current->isEnd();
    }

    bool startsWith(string &word){
        Node* current=this->root;
        for(char &ch:word){
            if(!current->containsKey(ch))
                return false;
            current=current->get(ch);
        }
        return true;
    }

    ~Trie() {
        delete root;
    }
};

int main() {
    
    return 0;
}
