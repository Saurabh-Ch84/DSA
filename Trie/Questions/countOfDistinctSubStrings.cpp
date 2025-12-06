#include<iostream>
using namespace std;

class Solution {
    class Trie{
            public:
        Trie* children[26];
        bool isEnd;
        
        Trie() {
            isEnd=false;
            for(int i=0;i<26;i++) 
                children[i]=nullptr;
        }
    };
  public:
    int countSubs(string& s) {
        // code here
        Trie* root=new Trie();
        int n=s.length(),count=0;
        
        for(int i=0;i<n;i++){
            Trie* current=root;
            for(int j=i;j<n;j++){
                int idx=s[j]-'a';
                if(!current->children[idx]){
                    current->children[idx]=new Trie();
                    count++;
                }
                current=current->children[idx];
            }
        }
        
        return count;
    }
};

/*You are required to complete this method */
class Node{
    Node *link[26];
        public:
    Node(){
        for(int i=0;i<26;i++) link[i]=nullptr;
    }
        
    bool containsKey(char ch){
        return link[ch-'a'];
    }
    
    Node *get(char ch){
        return link[ch-'a'];
    }
    
    void put(char ch,Node *node){
        link[ch-'a']=node;
    }
};

int countDistinctSubstring(string s) {
    // Your code here
    int answer=0;
    int n=s.length();
    Node *root=new Node();
    for(int i=0;i<n;i++)
    {
        Node *current=root;
        for(int j=i;j<n;j++)
        {
            if(!current->containsKey(s[j])){
                answer++;
                current->put(s[j],new Node());
            }
            current=current->get(s[j]);
        }
    }
    return answer+1;
}

int main(){

return 0;
}