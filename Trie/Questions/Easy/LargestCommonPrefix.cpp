#include<bits/stdc++.h>
using namespace std;

class Trie{
    class Node{
            public:
        int count;
        Node* children[26];
        Node(){
            count=0;
            for(int i=0;i<26;i++)
                children[i]=nullptr;
        }
    };
    Node *root;
        public:
    Trie(){
        root=new Node();
    }
    void insert(string &word){
        Node* curr=root;
        for(const char &letter: word){
            int idx=letter-'a';
            if(!curr->children[idx])
                curr->children[idx]=new Node();
            curr=curr->children[idx];
            curr->count++;
        }
    }
    string largestCommonPrefixSearch(int n){
        Node* curr=root;
        string res;
        while(curr){
            bool flag=0;
            for(int i=0;i<26;i++){
                if(curr->children[i] && curr->children[i]->count==n){
                    char letter='a'+i;
                    res.push_back(letter);
                    curr=curr->children[i];
                    flag=1;
                    break;
                }
            }
            if(!flag) curr=nullptr;
        }
        return res;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;
        int n=strs.size(), len;
        for(int i=0;i<n;i++)
            t.insert(strs[i]);
        return t.largestCommonPrefixSearch(n);
    }
};

int main(){

return 0;
}