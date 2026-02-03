#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using vi = vector<int> ;
using vc = vector<char> ;
using pii = pair<int,int> ;
using vvi = vector<vi> ;
using vpii = vector<pii> ;
using vvpii = vector<vpii> ;

// optimised
class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        queue<char> q;
        vi prefixArr(26,0);
        int n=s.length();
        string result;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            prefixArr[idx]++;
            if(prefixArr[idx]==1) q.push(s[i]);
            while(!q.empty() && prefixArr[q.front()-'a']>1)
                q.pop();
            result.push_back(q.empty()? '#':q.front());
        }
        return result;
    }
};

// naive
class Solution {
    void fixQueue(queue<char> &q,char ch){
        queue<char> q_;
        while(!q.empty()){
            char ch_=q.front();q.pop();
            if(ch_==ch) continue;
            q_.push(ch_);
        }
        q=q_;
    }
  public:
    string firstNonRepeating(string &s) {
        // code here
        queue<char> q;
        vi prefixArr(26,0);
        int n=s.length();
        string result;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            prefixArr[idx]++;
            if(prefixArr[idx]==1) q.push(s[i]);
            else if(prefixArr[idx]==2) fixQueue(q,s[i]);
            char ch=(q.empty()? '#': q.front());
            result.push_back(ch);
        }
        return result;
    }
};


class Solution {
    const int INF=1e9;
    void dijsktra(vvi &dist,int src,vvpii &adjList){
        priority_queue<pii,vpii,greater<pii>> pq;
        pq.push({0,src});
        dist[src][src]=0;

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
public:
    long long minimumCost(string source,string target,vc &original,vc &changed,vi &cost) {
        int n=cost.size(), m=source.size();
        vvpii adjList(26);
        for(int i=0;i<n;i++){
            int u=original[i]-'a', v=changed[i]-'a', w=cost[i];
            adjList[u].push_back({w,v});
        }

        vvi dist(26,vi(26,INF));
        for(int i=0;i<26;i++)
            dijsktra(dist,i,adjList);

        long long minCost=0;
        for(int i=0;i<m;i++){
            int src=source[i]-'a', dest=target[i]-'a';
            if(dist[src][dest]==INF) return -1;
            minCost+=dist[src][dest];
        }
        return minCost;
    }
};

int main(){

return 0;
}