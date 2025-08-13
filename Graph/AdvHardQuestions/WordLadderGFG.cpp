#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

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

int main(){

return 0;
}