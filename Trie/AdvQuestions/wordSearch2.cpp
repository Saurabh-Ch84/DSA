#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
using vi = vector<int> ;
using vs = vector<string> ;
using vvc = vector<vector<char>>;

class Solution {
    class Trie{
        public:
    Trie* children[26];
    bool isEnd;
        Trie() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
        void insert(string &word) {
            Trie* currentNode = this;
            for (char letter : word) {
                int idx = letter - 'a';
                if (!currentNode->children[idx])
                    currentNode->children[idx] = new Trie();
                currentNode = currentNode->children[idx];
            }
            currentNode->isEnd = true;
        }
    };

    bool isValid(int i,int j,int n,int m){
        return (i<n && j<m && i>=0 && j>=0);
    }

    void DFS(int i,int j,int n,int m,string &str,vvc &board,Trie* currentNode,unordered_set<string> &hashSet,vi &di,vi &dj){
        char ch=board[i][j];
        board[i][j]='#';
        Trie* newNode=currentNode->children[ch-'a'];
        if(newNode){
            str.push_back(ch);
            if(newNode->isEnd)
                hashSet.insert(str);
            for(int k=0;k<4;k++){
                int i_=i+di[k],j_=j+dj[k];
                if(!isValid(i_,j_,n,m) || board[i_][j_]=='#') continue;
                DFS(i_,j_,n,m,str,board,newNode,hashSet,di,dj);
            }
            str.pop_back();
        }
        board[i][j]=ch;
    }
public:
    vector<string> findWords(vvc &board,vs &words){
        Trie* trie=new Trie();
        unordered_set<string> hashSet;
        for(string &word: words)
            trie->insert(word);
        
        int n=board.size(),m=board[0].size();
        vi di={-1,0,1,0},dj={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string str;
                DFS(i,j,n,m,str,board,trie,hashSet,di,dj);
            }
        }
        vs ans(hashSet.begin(),hashSet.end());
        return ans;
    }
};

int main(){

return 0;
}