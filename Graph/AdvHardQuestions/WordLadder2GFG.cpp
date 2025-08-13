#include<iostream>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;

// User function Template for C++

class Solution {
    vector<vector<string>> BFS(vector<string> &wordList,string &targetWord,int startIndx){
        
        vector<vector<string>> ans;
        queue<vector<string>> ladderQ;
        ladderQ.push({wordList[startIndx]});
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        bool found=false;
        while(!ladderQ.empty() && !found){
            int size=ladderQ.size();
            unordered_set<string> visitedThisLevel;
            for(int j=0;j<size;j++)
            {
                vector<string> path=ladderQ.front();
                ladderQ.pop();
                string lastWord=path.back();
                for(int i=0;i<lastWord.length();i++)
                {
                    char letter=lastWord[i];
                    string temp=lastWord;
                    for(char ch='a';ch<='z';ch++)
                    {
                        if(ch==letter) continue;
                        temp[i]=ch;
                        if(wordSet.count(temp)) 
                        {
                            vector<string> newPath = path;
                            newPath.push_back(temp);
                            if (temp == targetWord) {
                                ans.push_back(newPath);
                                found = true;
                            } 
                            else
                                ladderQ.push(newPath);
                            visitedThisLevel.insert(temp);
                        }
                    }
                }
            }
            for(const string &usedWord : visitedThisLevel)
                wordSet.erase(usedWord);
        }
        return ans;
    }
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,vector<string>& wordList) {
        // code here
        bool checkEndWord=false;
        int startIndx=-1;
        for(int i=0;i<wordList.size();i++){
            if(startIndx==-1 && wordList[i]==beginWord) startIndx=i;
            if(wordList[i]==endWord) checkEndWord=true;
            if(startIndx!=-1 && checkEndWord) break;
        }
        if(!checkEndWord) return {};
        if(startIndx==-1){
            startIndx=wordList.size();
            wordList.push_back(beginWord);
        }
        return BFS(wordList,endWord,startIndx);
    }
};

int main(){

return 0;
}