#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vstr=vector<string>;
    class Trie{
        class Node{
                public:
            bool isEnd;
            Node *child[26];
            int count;
            Node(){
                isEnd=false;
                count=0;
                for(int i=0;i<26;i++)
                    child[i]=nullptr;
            }
        };
            public:
        Node* root;
        Trie(){
            root=new Node();
        }
        void insert(string &str){ 
            Node* curr=root;
            for(const char &ch: str){
                int idx=ch-'a';
                if(!curr->child[idx])
                    curr->child[idx]=new Node();
                curr=curr->child[idx];
                curr->count++;
            }
            curr->isEnd=1;
        }
        string customSearch(string &str){ 
            string ans;
            Node* curr=root;
            for(const char &ch: str){
                int idx=ch-'a';
                if(curr->count==1) break;
                ans.push_back(ch);
                curr=curr->child[idx];
            }
            return ans;
        }
    };
  public:
    vstr findPrefixes(vstr &arr) {
        // code here
        int n=arr.size();
        Trie t;
        for(int i=0;i<n;i++)
            t.insert(arr[i]);
        vstr ans(n);
        for(int i=0;i<n;i++)
            ans[i]=t.customSearch(arr[i]);
        return ans;
    }
};

int main(){

return 0;
}