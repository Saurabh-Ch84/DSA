#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using vs=vector<string>;

class SolutionBrute {
    class Trie{
        int BFS(Trie *current){
            queue<Trie*>q;
            q.push(current);

            int idx=1e9;
            while(!q.empty()){
                int sz=q.size();
                while(sz--){
                    Trie *node=q.front(); q.pop();
                    if(node->index!=-1) 
                        idx=min(idx,node->index);
                    for(int i=0;i<26;i++){
                        if(node->children[i]){
                            q.push(node->children[i]);
                        }
                    }
                }
                if(idx!=1e9) return idx;
            }

            return -1; //dummy return
        }
            public:
        Trie* children[26];
        int index;

        Trie(){
            index=-1;
            for(int i=0;i<26;i++)
                children[i]=nullptr;
        }

        void insert(int idx,const string &word){
            Trie *current=this;
            int n=word.length();
            for(int i=n-1;i>=0;i--){
                int j=word[i]-'a';
                if(!current->children[j])
                    current->children[j]=new Trie();
                current=current->children[j];
            }
            if(current->index!=-1) current->index=min(current->index,idx);
            else current->index=idx;
        }

        int startsWith(const string &word,int miniIdx){
            Trie *current=this;
            int n=word.length();
            for(int i=n-1;i>=0;i--){
                int j=word[i]-'a';
                if(!current->children[j]){
                    if(i==n-1) return miniIdx;
                    return BFS(current);
                }
                current=current->children[j];
            }
            return BFS(current);
        }
    };
public:
    vector<int> stringIndices(vs &wordsContainer, vs &wordsQuery){
        Trie t;
        int n=wordsContainer.size(), miniIdx=0;
        for(int i=0;i<n;i++){
            t.insert(i,wordsContainer[i]);
            if(wordsContainer[i].length()<wordsContainer[miniIdx].length())
                miniIdx=i;
        }

        vector<int> result;
        for(const string &query: wordsQuery){
            result.push_back(t.startsWith(query, miniIdx));
        }
        return result;
    }
};


class SolutionOptimal {
    class Trie{
            public:
        Trie* child[26];
        int index;

        Trie(){
            index=1e7;
            for(int i=0;i<26;i++)
                child[i]=nullptr;
        }

        void insert(int depthBound,int idx,const string &word,vs &wordsContainer){
            Trie *curr=this;
            int n=word.size(), i=n-1;
            // optimization
            while(depthBound && i>=0){
                int j=word[i]-'a';
                if(!curr->child[j])
                    curr->child[j]=new Trie();
                //optimization
                if(curr->child[j]->index==1e7 || wordsContainer[curr->child[j]->index].size()>n)
                    curr->child[j]->index=idx;
                curr=curr->child[j];
                depthBound--;
                i--;
            }
            curr->index=min(curr->index,idx);
        }

        int startsWith(const string &word,int miniIdx){
            Trie *curr=this;
            int n=word.length(), i=n-1;
            while(i>=0){
                int j=word[i]-'a';
                if(!curr->child[j]){
                    if(i==n-1) return miniIdx;
                    break;
                }
                curr=curr->child[j];
                i--;
            }
            //optimization
            return curr->index;
        }
    };
public:
    vector<int> stringIndices(vs &wordsContainer, vs &wordsQuery){
        Trie t;
        int n=wordsContainer.size(), miniIdx=0, m=wordsQuery.size(), depthBound=-1;
        //optimization
        for(int i=0;i<m;i++)
            depthBound=max(depthBound,(int)wordsQuery[i].size());

        for(int i=0;i<n;i++){
            t.insert(depthBound,i,wordsContainer[i],wordsContainer);
            if(wordsContainer[i].size()<wordsContainer[miniIdx].size())
                miniIdx=i;
        }

        vector<int> result;
        for(const string &query: wordsQuery){
            result.push_back(t.startsWith(query, miniIdx));
        }

        return result;
    }
};


int main(){

return 0;
}