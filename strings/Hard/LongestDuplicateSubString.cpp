#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    // using suffix Array
    class SuffixArray{
        vector<int> suffixIdxArr;
        const string &s;
        struct SuffixComp{
            const string &s;
            SuffixComp(const string &s):s(s){}
            bool operator()(const int aIdx,const int bIdx) const{
                return string_view(s).substr(aIdx)<string_view(s).substr(bIdx);
            }
        };
            public:
        SuffixArray(const string &s):s(s){
            int n=s.size();
            suffixIdxArr.resize(n);
            for(int i=0;i<n;i++)
                suffixIdxArr[i]=i;
            sort(suffixIdxArr.begin(),suffixIdxArr.end(),SuffixComp(s));    
        }
        string getLongestDuplicateSubString(){
            int n=suffixIdxArr.size(), maxLen=0, start=-1;
            for(int i=0;i<n-1;i++){
                int j1=suffixIdxArr[i], j2=suffixIdxArr[i+1];
                string_view s1=string_view(s).substr(j1);
                string_view s2=string_view(s).substr(j2);
                int limit=min(s1.size(),s2.size());
                if(limit<=maxLen) continue;
                int k=0;
                while(k<limit && s1[k]==s2[k]) k++;
                if(k>maxLen){
                    start=j1;
                    maxLen=k;
                }
            }
            if(start==-1) return "";
            return s.substr(start,maxLen);
        }
    };
public:
    string longestDupSubstring(string s) {
        SuffixArray sa(s);
        return sa.getLongestDuplicateSubString();
    }
};

using vi = vector<int> ;
class Solution2 {
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
        unordered_map<int,int> hashMap;
        int key=0;
        for(int i=0;i<mid;i++)
            key=(1LL*key*26+(s[i]-'a'+1))%p;
        
        hashMap[key]=0;
        for(int i=1;i<n-mid+1;i++){
            key=(key-(1LL*roll[mid-1]*(s[i-1]-'a'+1))%p+p)%p;
            key=(1LL*key*26+(s[i+mid-1]-'a'+1))%p;
            if(hashMap.count(key)){
                int i_=hashMap[key];
                if(s.substr(i,mid)==s.substr(i_,mid))
                    return i;
            }
            hashMap[key]=i;
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

class Solution3 {
    class Trie{
        struct Node{
            Node* children[26];
            bool isEnd;
            Node(){
                isEnd=0;
                for(int i=0;i<26;i++)
                    children[i]=nullptr;
            }
        };
        Node* root;
            public:
        Trie(){ root=new Node(); }
        bool insert(string s){
            Node* curr=root;
            for(char letter:s){
                int idx=letter-'a';
                if(!curr->children[idx])
                    curr->children[idx]=new Node();
                curr=curr->children[idx];
            }
            if(curr->isEnd) return 1;
            curr->isEnd=1;
            return 0;
        }
    };
    int check(int mid,string &s,int n){
        Trie t;
        for(int i=0;i<n-mid+1;i++){
            if(t.insert(s.substr(i,mid)))
                return i;
        }
        return -1;
    }
public:
    string longestDupSubstring(string s) {
        int n=s.size();
        int low=1, high=n-1;
        int start=-1, maxLen=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int responseIdx=check(mid,s,n);
            if(responseIdx!=-1){
                start=responseIdx;
                maxLen=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return (start==-1? "":s.substr(start,maxLen));
    }
};

int main(){

return 0;
}