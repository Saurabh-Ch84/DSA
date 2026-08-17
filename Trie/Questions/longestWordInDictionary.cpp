#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    // brute force O(nlogn) + O(n*l^2)
    class Trie{
        class Node{
                public:
            bool isEnd;
            Node* children[26];
            Node(){
                isEnd=false;
                for(int i=0;i<26;i++)
                    children[i]=nullptr;
            }
            ~Node(){
                for(int i=0;i<26;i++)
                    delete children[i];
            }
        };
        Node* root;
            public:
        Trie(){
            root=new Node();
        }
        void insert(string &word){
            Node* curr=this->root;
            for(const char &letter: word){
                int idx=letter-'a';
                if(!curr->children[idx])
                    curr->children[idx]=new Node();
                curr=curr->children[idx];
            }
            curr->isEnd=true;
        }
        bool search(string &word){
            Node* curr=this->root;
            for(const char &letter: word){
                int idx=letter-'a';
                if(!curr->children[idx])
                    return false;
                curr=curr->children[idx];
            }
            return curr->isEnd;
        }
    };
    struct Comp{
        bool operator()(const string &a,const string &b){
            // we are comparing the lengths of the two strings, 
            // if they are equal, then we compare the strings lexicographically.
            int sA=a.size(), sB=b.size();
            if(sA==sB) return a<b;
            // if the lengths are not equal, then we return true if the length of a is greater than the length of b,
            // because we want to sort the strings in descending order of their lengths.
            if(sA>sB) return true;
            return false;
        }
    };
    bool allPrefixesFound(string &word,Trie &t){
        string prefix="";
        for(const char &letter:word){
            prefix+=letter;
            if(!t.search(prefix)) 
                return false;
        }
        // if we have found all the prefixes of the word in the trie, then we return true.
        return true;
    }
public:
    string longestWord(vector<string>& words) {
        Trie t;
        sort(words.begin(),words.end(),Comp());
        for(string &word: words){
            t.insert(word);
        } 
        for(string &word: words){
            if(allPrefixesFound(word,t))
                return word;
        }
        return "";
    }
};

class Solution2 {
    // optimized approach O(nlogn) + O(n*l)
    class Trie{
        class Node{
                public:
            bool isEnd;
            Node* children[26];
            Node(){
                isEnd=false;
                for(int i=0;i<26;i++)
                    children[i]=nullptr;
            }
            ~Node(){
                for(int i=0;i<26;i++)
                    delete children[i];
            }
        };
        Node* root;
            public:
        Trie(){
            root=new Node();
        }
        bool insert(string &word){
            Node* curr=this->root;
            int prefixFoundCount=0;
            for(const char &letter: word){
                int idx=letter-'a';
                if(!curr->children[idx]){
                    curr->children[idx]=new Node();
                }
                curr=curr->children[idx];
                prefixFoundCount+=curr->isEnd;
            }
            curr->isEnd=true;
            // if the number of prefixes found is equal to the length of the word minus 1, then we return true.
            return (prefixFoundCount+1==word.size());
        }
        ~Trie(){ delete root; }
    };
    struct Comp{
        bool operator()(const string &a,const string &b){
            // sort the strings in lexicographical order if they are of the same length, 
            // otherwise sort them in increasing order of their lengths.
            int sA=a.size(), sB=b.size();
            if(sA==sB) return a<b;
            if(sA<sB) return true;
            return false;
        }
    };
public:
    string longestWord(vector<string>& words) {
        Trie t;
        sort(words.begin(),words.end(),Comp());
        int idx=-1, n=words.size();
        for(int i=0;i<n;i++){
            // since we have sorted in lexicographical order, we can just check if the current word can be inserted 
            // into the trie and if it is longer than the previous longest word.
            if(t.insert(words[i]) && (idx==-1 || words[i].size()>words[idx].size()))
                idx=i;
        }
        return (idx==-1? "": words[idx]);
    }
};


int main(){

return 0;
}