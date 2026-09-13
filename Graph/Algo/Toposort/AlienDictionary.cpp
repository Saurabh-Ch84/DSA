#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

using vi = vector<int> ;
using vc = vector<char> ;
using u_mci = unordered_map<char,int> ; 
using u_mcvc = unordered_map<char,vc> ; 

class Solution {
    bool process(string &a,string &b,u_mci &indegree,u_mcvc &adjMap){
        int n=min(a.length(),b.length());
        int ptr=0;
        while(ptr<n){
            if(a[ptr]!=b[ptr]){
                char u=a[ptr],v=b[ptr];
                indegree[v]++;
                adjMap[u].push_back(v);
                return true;
            }   
            ptr++;
        }
        return a.length()<=b.length();
    }
    string topoSort(u_mci &indegree,u_mcvc &adjMap){
        int m=indegree.size();
        queue<char> q;
        for(auto &p: indegree){
            char ch=p.first;
            int deg=p.second;
            if(deg==0){
                q.push(ch);
            }
        }
        string result;
        while(!q.empty()){
            char u=q.front();q.pop();
            result.push_back(u);
            for(char v: adjMap[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return (result.size()==m ? result: string());
    }
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n=words.size();
        u_mci indegree;
        for(string &word: words){
            for(char letter: word) indegree[letter]=0;
        }
        u_mcvc adjMap;
        for(int i=0;i<n-1;i++){
            if(!process(words[i],words[i+1],indegree,adjMap))
                return "";
        }
        string order=topoSort(indegree,adjMap);
        return order;
    }
};

class Solution {
    pair<char,char> findNodes1(string &a,string &b){
        int left=0,right=0;
        while(left<a.length() && right<b.length() && a[left]==b[right]){
            left++,right++;
        }   
        char u='_',v='_';
        if(left<a.length() && right<b.length())
            u=a[left],v=b[right];
        return {u,v};
    }

    pair<char,char> findNodes2(const string &a,const string &b){
        int ptr=0,len=min(a.length(),b.length());
        while(ptr<len && a[ptr]==b[ptr]) ptr++;
        if (ptr == len) return {'_', '_'};
        return {a[ptr],b[ptr]};
    }

    string BFS(unordered_map<char,vector<char>> &adjM,unordered_map<char,int> &indegreeM){
        string answer="";
        queue<char> q;
        for(pair<char,int> p:indegreeM)
            if(!p.second) q.push(p.first);
        
        while(!q.empty()){
            char u=q.front();
            q.pop();
            answer+=u;
            for(char &v:adjM[u]){
                indegreeM[v]--;
                if(!indegreeM[v]) q.push(v);
            }
        }
        return answer;
    }

  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char,int> indegreeMap;
        for(string &word:words)
            for(char &letter:word)
                indegreeMap[letter];
                
        int V=indegreeMap.size();
        unordered_map<char,vector<char>> adjMap;
        
        for(int i=1;i<words.size();i++){
            pair<char,char> nodes=findNodes2(words[i-1],words[i]);
            if(nodes.first==nodes.second && words[i-1].length()>words[i].length()) return "";
            else if(nodes.first==nodes.second) continue;
            indegreeMap[nodes.second]++;
            adjMap[nodes.first].push_back(nodes.second);
        }
        
        string result=BFS(adjMap,indegreeMap);
        return (result.size()==V)? result:"";
    }
    
};

int main(){

return 0;
}