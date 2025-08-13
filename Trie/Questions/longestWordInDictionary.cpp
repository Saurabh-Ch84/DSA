#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    Node *link[26];
    bool flag;
public:
    Node(){
        for(int i=0;i<26;i++) link[i]=nullptr;
        flag=false;
    }

    bool containsKey(char ch){
        return link[ch-'a']!=nullptr;
    }

    void setEnd(){
        flag=true;
    }

    Node *get(char ch){
        return link[ch-'a'];
    }

    void put(char ch,Node *node){
        link[ch-'a']=node;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    Node * root;
public:
    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node* current=root;
        for(char &ch:word){
            if(!current->containsKey(ch)) current->put(ch,new Node());
            current=current->get(ch);
        }
        current->setEnd();
    }

    bool search(string &word){
        Node* current=root;
        for(char &ch:word){
            if(!current->containsKey(ch)) return false;
            current=current->get(ch);
        }
        return current->isEnd();
    }
};


class Solution {
    static bool comp(const string &a,const string &b){
        if(a.length()==b.length()) return a<b;
        return a.length()>b.length();
    }
    bool allPrefixesFound(string &word,Trie &trie){
        string res="";
        for(char &letter:word){
            res+=letter;
            if(!trie.search(res)) return false;
        }
        return true;
    }
public:
    string longestWord(vector<string>& words) {
        Trie t;
        for(string &word:words) t.insert(word);
        sort(words.begin(),words.end(),comp);
        for(string &word:words)
            if(allPrefixesFound(word,t)) return word;
        return "";
    }
};



int main(){

return 0;
}