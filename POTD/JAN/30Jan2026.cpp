#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;
using s = string;
using pii = pair<int,int> ;
using vpii = vector<pii> ;
using vvpii = vector<vpii> ;
using vi = vector<int> ;
using vll = vector<long long> ;
using vvi = vector<vi> ;
using vs = vector<string> ;
using memo = unordered_map<s,int> ;

class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n=q.size()/2;
        queue<int> first, second;
        while(!q.empty()){
            if(first.size()<n){
                first.push(q.front());
            }else{
                second.push(q.front());
            }
            q.pop();
        }
        
        while(!first.empty() || !second.empty()){
            if(first.size()==second.size()){
                q.push(first.front());
                first.pop();
            }else{
                q.push(second.front());
                second.pop();
            }
        }
    }
};

class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n=q.size(), idx=0;
        vi arr(n,0);
        while(!q.empty()){
            int top=q.front(); q.pop();
            arr[idx]=top;
            idx=(idx+2)%n;
            if(!idx) idx++;
        }
        for(int i=0;i<n;i++){
            q.push(arr[i]);
        }
    }
};

class Solution1 {
    const int inf=1e9;
    const long long INF=1e18;

    void dijsktra(int src,vvpii &adjList,vvi &dist){
        priority_queue<pii,vpii,greater<pii>> pq;
        dist[src][src]=0;
        pq.push({0,src});

        while(!pq.empty()){
            pii entry=pq.top();pq.pop();
            int d=entry.first, u=entry.second;
            if(dist[src][u]<d) continue;
            for(auto &p: adjList[u]){
                int d_=p.first+d, v=p.second;
                if(dist[src][v]>d_){
                    dist[src][v]=d_;
                    pq.push({d_,v});
                }
            }
        }
    }

    long long recursion(int i,int len,s &source,s &target,memo &hashMap,vvi &dist,vll &dp){
        if(i>=len) return 0;
        if(dp[i]!=-1) return dp[i];
        long long takeLength=INF, takeOne=INF;
        if(source[i]==target[i])
            takeOne=recursion(i+1,len,source,target,hashMap,dist,dp);
        string temp1, temp2;
        for(int j=i;j<len;j++){
            temp1.push_back(source[j]);
            temp2.push_back(target[j]);
            if(hashMap.count(temp1) && hashMap.count(temp2)){
                int u=hashMap[temp1], v=hashMap[temp2];
                if(dist[u][v]==inf) continue;
                long long next=dist[u][v]+recursion(j+1,len,source,target,hashMap,dist,dp);
                takeLength=min(takeLength,next);
            }
        }
        return dp[i]=min(takeLength,takeOne);
    }
public:
    long long minimumCost(s source,s target,vs &original,vs &changed,vi &cost) {
        int n=cost.size();
        memo hashMap;
        for(int i=0;i<n;i++){
            if(!hashMap.count(original[i])){
                int sz=hashMap.size();
                hashMap[original[i]]=sz;
            }
            if(!hashMap.count(changed[i])){
                int sz=hashMap.size();
                hashMap[changed[i]]=sz;
            }
        }
 
        int m=hashMap.size();
        vvpii adjList(m);
        for(int i=0;i<n;i++){
            int u=hashMap[original[i]], v=hashMap[changed[i]], w=cost[i];
            adjList[u].push_back({w,v});
        }

        vvi dist(m,vi(m,inf));
        for(int i=0;i<m;i++){
            dijsktra(i,adjList,dist);
        }

        int len=source.length();
        vll dp(len,-1);
        long long result=recursion(0,len,source,target,hashMap,dist,dp);
        return (result==INF ? -1: result);
    }
};


class Solution {
    class TrieNode{
            public:
        int id;
        TrieNode* children[26];
        TrieNode(){
            id=-1;
            for(int i=0;i<26;i++)
                children[i]=nullptr;
        }
    };

    class Trie{
            public:
        TrieNode* root;
        Trie(){
            root=new TrieNode();
        }
        void insert(string &word,int id){
            TrieNode* curr=root;
            for(char ch: word){
                if(!curr->children[ch-'a'])
                    curr->children[ch-'a']=new TrieNode();
                curr=curr->children[ch-'a'];
            }
            curr->id=id;
        }
    };

    const int inf=1e9;
    const long long INF=1e18;

    void dijsktra(int src,vvpii &adjList,vvi &dist){
        priority_queue<pii,vpii,greater<pii>> pq;
        dist[src][src]=0;
        pq.push({0,src});

        while(!pq.empty()){
            pii entry=pq.top();pq.pop();
            int d=entry.first, u=entry.second;
            if(dist[src][u]<d) continue;
            for(auto &p: adjList[u]){
                int d_=p.first+d, v=p.second;
                if(dist[src][v]>d_){
                    dist[src][v]=d_;
                    pq.push({d_,v});
                }
            }
        }
    }

    long long recursion(int i,int len,s &source,s &target,vvi &dist,Trie &originalTrie,Trie &changedTrie,vll &dp){
        if(i>=len) return 0;
        if(dp[i]!=-1) return dp[i];
        long long takeLength=INF, takeOne=INF;
        if(source[i]==target[i])
            takeOne=recursion(i+1,len,source,target,dist,originalTrie,changedTrie,dp);

        TrieNode* node1=originalTrie.root;
        TrieNode* node2=changedTrie.root;
        for(int j=i;j<len;j++){
            int idx1=source[j]-'a', idx2=target[j]-'a';
            if(!node1->children[idx1] || !node2->children[idx2])
                break;
            node1=node1->children[idx1];
            node2=node2->children[idx2];
            if(node1->id!=-1 && node2->id!=-1){
                int u=node1->id, v=node2->id;
                if(dist[u][v]==inf) continue;
                long long next=dist[u][v]+recursion(j+1,len,source,target,dist,originalTrie,changedTrie,dp);
                takeLength=min(takeLength,next);
            }
        }
        return dp[i]=min(takeLength,takeOne);
    }


public:
    long long minimumCost(s source,s target,vs &original,vs &changed,vi &cost) {
        if(source.size() != target.size()) return -1;
        int n=cost.size();
        memo hashMap;
        for(int i=0;i<n;i++){
            if(!hashMap.count(original[i])){
                int sz=hashMap.size();
                hashMap[original[i]]=sz;
            }
            if(!hashMap.count(changed[i])){
                int sz=hashMap.size();
                hashMap[changed[i]]=sz;
            }
        }
 
        Trie originalTrie;
        Trie changedTrie;
        int m=hashMap.size();
        vvpii adjList(m);
        for(int i=0;i<n;i++){
            int u=hashMap[original[i]], v=hashMap[changed[i]], w=cost[i];
            originalTrie.insert(original[i],u);
            changedTrie.insert(changed[i],v);
            adjList[u].push_back({w,v});
        }

        vvi dist(m,vi(m,inf));
        for(int i=0;i<m;i++){
            dijsktra(i,adjList,dist);
        }

        int len=source.length();
        vll dp(len,-1);
        long long result=recursion(0,len,source,target,dist,originalTrie,changedTrie,dp);
        return (result==INF ? -1: result);
    }
};

int main(){

return 0;
}