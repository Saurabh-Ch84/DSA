#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

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