#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

using vi = vector<int> ;

class Solution {
    class Trie{
        Trie* children[26];
        bool isEnd;
            public:
        Trie() {
            isEnd=false;
            for(int i=0;i<26;i++) 
                children[i]=nullptr;
        }

        bool insert(string word){
            Trie* current=this;
            for(char letter: word){
                int idx=letter-'a';
                if(!current->children[idx])
                    current->children[idx]=new Trie();
                current=current->children[idx];
            }
            if(current->isEnd) return true;
            current->isEnd=true;
            return false;
        }
    };

    int funTrie(string &s,int mid,int n){
        Trie *trie=new Trie();
        for(int i=0;i<n-mid+1;i++){
            if(trie->insert(s.substr(i,mid)))
                return i;
        }
        return -1;
    }

    int funRollingHash(string &s,int mid,int n,vi &roll,int p){
        unordered_map<int,vi> hashMap;
        int key=0;
        for(int i=0;i<mid;i++)
            key=(1LL*key*26+(s[i]-'a'+1))%p;
        
        hashMap[key].push_back(0);
        for(int i=1;i<n-mid+1;i++){
            key=(key-(1LL*roll[mid-1]*(s[i-1]-'a'+1))%p+p)%p;
            key=(1LL*key*26+(s[i+mid-1]-'a'+1))%p;
            if(hashMap.count(key)){
                for(int &i_ :hashMap[key]){
                    if(s.substr(i,mid)==s.substr(i_,mid))
                        return i;
                }
            }
            hashMap[key].push_back(i);
        }
        return -1;
    }
public:
    string longestDupSubstring(string s) {
        int n=s.length(),p=1e9+7;
        int low=1,high=n-1;
        int maxi=0,idx=-1;

        vi roll(n+1,1);
        for(int i=1;i<=n;i++)
            roll[i]=(1LL*26*(roll[i-1])%p)%p;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            // int response=funTrie(s,mid,n);
            int response=funRollingHash(s,mid,n,roll,p);
            if(response!=-1){
                idx=response;
                maxi=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return (idx==-1) ? "": s.substr(idx,maxi);
    }
};

int main(){

return 0;
}