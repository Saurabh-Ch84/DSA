#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

using um_si = unordered_map<string,int> ;
using vs = vector<string> ;

class Solution {
    int BFS(int idx,string &beginWord,string &endWord,um_si &hashMap,vs &wordList){
        int n=wordList.size();
        int ladderLength=0;
        queue<int> q;
        vector<int> visited(n,false);
        visited[idx]=true;
        q.push(idx);
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int i=q.front();q.pop();
                string currWord=wordList[i];
                if(currWord==endWord) return ladderLength+1;
                int m=currWord.length();
                for(int j=0;j<m;j++){
                    char orig=currWord[j];
                    for(char ch='a';ch<='z';ch++){
                        if(orig==ch) continue;
                        currWord[j]=ch;
                        if(hashMap.count(currWord)){
                            int k=hashMap[currWord];
                            if(visited[k]==false){
                                q.push(k);
                                visited[k]=true;
                            }
                        }
                    }
                    currWord[j]=orig;
                }
            }
            ladderLength++;
        }
        return 0;
    }
public:
    int wordLadderLength(string startWord, string endWord, vector<string>& wordList) {
        int n=wordList.size(),idx=-1;
        bool isEndWord=false;
        um_si hashMap;
        for(int i=0;i<n;i++){
            if(wordList[i]==startWord) idx=i;
            if(wordList[i]==endWord) isEndWord=true;
            hashMap[wordList[i]]=i;
        }
        
        if(isEndWord==false) return 0;
        if(idx==-1){
            idx=n;
            hashMap[startWord]=n;
            wordList.push_back(startWord);
        }
        return BFS(idx,startWord,endWord,hashMap,wordList);
    }
};
                             
                            
class Solution {
    //better approach
    int BFS1(vector<string> &wordList,string &targetWord,int startIndx,unordered_map<string,int> &wordMap){
        queue<int> q;
        q.push(startIndx);
        int ladderLength=1;
        while(!q.empty()){
            int size=q.size();
            for(int j=0;j<size;j++)
            {
                int node=q.front();
                string str=wordList[node];
                q.pop();
                if(str==targetWord) return ladderLength;
                for(int i=0;i<str.length();i++)
                {
                    char letter=str[i];
                    string temp=str;
                    for(char ch='a';ch<='z';ch++)
                    {
                        if(ch==letter) continue;
                        temp[i]=ch;
                        if(wordMap.find(temp)!=wordMap.end())
                        {
                            q.push(wordMap[temp]);
                            wordMap.erase(temp);
                        }
                    }
                }
            }
            ladderLength++;
        }
        return 0;
    }
    
    int BFS2(vector<string> &wordList,string &targetWord,int startIndx,unordered_map<string,int> &wordMap){
        queue<pair<int,int>> q;
        q.push({startIndx,1});
        int level=0;
        while(!q.empty()){
            int node=q.front().first;
            int step=q.front().second;
            q.pop();
            string str=wordList[node];
            if(str==targetWord) return step;
            for(int i=0;i<str.length();i++){
                char letter=str[i];
                string temp=str;
                for(char ch='a';ch<='z';ch++){
                    if(ch==letter) continue;
                    temp[i]=ch;
                    if(wordMap.find(temp)!=wordMap.end()){
                        q.push({wordMap[temp],step+1});
                        wordMap.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
    
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        // Code here
        bool checkEndWord=false;
        int startIndx=-1;
        unordered_map<string,int> wordMap;
        for(int i=0;i<wordList.size();i++){
            wordMap[wordList[i]]=i;
            if(startIndx==-1 && wordList[i]==startWord) startIndx=i;
            if(wordList[i]==targetWord) checkEndWord=true;
        }
        if(!checkEndWord) return 0;
        if(startIndx==-1){
            startIndx=wordList.size();
            wordList.push_back(startWord);
        }
        return BFS1(wordList,targetWord,startIndx,wordMap);
    }
};


class Solution {
    bool isConnected(string &u,string &v,int m){
        int changes=0,ptr=0;
        while(ptr<m){
            if(u[ptr]!=v[ptr]){
                if(changes) return false;
                changes++;
            }
            ptr++;
        }
        return true;
    }

    int BFS(int idx,string &beginWord,string &endWord,vector<string> &wordList){
        int ladderLength=0,n=wordList.size();
        queue<int> q;
        vector<int> visited(n,false);
        q.push(idx);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int i=q.front();q.pop();
                visited[i]=true;
                string currWord=wordList[i];
                if(currWord==endWord) return ladderLength+1;
                int m=currWord.length();
                for(int j=0;j<n;j++){
                    if(i==j || wordList[j].length()!=m) continue;
                    if(visited[j]==false && isConnected(wordList[j],currWord,m)) q.push(j);
                }
            }
            ladderLength++;
        }
        return 0;
    }
public:
    int wordLadderLength(string startWord, string endWord, vector<string>& wordList) {
        int n=wordList.size(),idx=-1;
        bool isEndWord=false;
        for(int i=0;i<n;i++){
            if(wordList[i]==startWord) idx=i;
            if(wordList[i]==endWord) isEndWord=true;
        }
        if(isEndWord==false) return 0;
        if(idx==-1){
            idx=n;
            wordList.push_back(startWord);
        }
        return BFS(idx,startWord,endWord,wordList);
    }
};
                             
                    

int main(){

return 0;
}