#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vvvint=vector<vvint>;
    class Trie{
            class Node{
                    public:
                int count;
                Node* child[2];
                Node(){
                    count=0;
                    for(int i=0;i<2;i++)
                        child[i]=nullptr;
                }
                ~Node(){
                    for(int i=0;i<2;i++)
                        delete child[i];
                }
                void increment(){
                    count++;
                }
                void decrement(){
                    count--;
                }
            };
        Node* root;
            public:
        Trie(){
            root=new Node();
        }
        void insert(int num){
            Node* curr=root;
            for(int i=30;i>=0;i--){
                int bit=(num>>i) & 1;
                if(!curr->child[bit])
                    curr->child[bit]=new Node();
                curr=curr->child[bit];
                curr->increment();
            }
        }
        int maxXOR(int num){
            Node* curr=root;
            int ans=0;
            for(int i=30;i>=0;i--){
                int bit=(num>>i) & 1;
                int bit_=1^bit;
                if(curr->child[bit_] && curr->child[bit_]->count){
                    ans=ans|(1<<i);
                    curr=curr->child[bit_];
                }
                else curr=curr->child[bit];
            }
            return ans;
        }
        void remove(int num){
            Node* curr=root;
            for(int i=30;i>=0;i--){
                int bit=(num>>i) & 1;
                curr=curr->child[bit];
                curr->decrement();
            }
        }
        ~Trie(){
            delete root;
        }
    };
    void DFS(int u,vint &res,vvvint &offlineQuery,vvint &adjList,Trie &t){
        t.insert(u);
        vvint &myQuery=offlineQuery[u];
        int n=myQuery.size();
        for(int i=0;i<n;i++){
            int x=myQuery[i][0], ansIdx=myQuery[i][1];
            res[ansIdx]=t.maxXOR(x);
        }
        for(int &v: adjList[u])
            DFS(v,res,offlineQuery,adjList,t);
        t.remove(u);
    }
public:
    vint maxGeneticDifference(vint &parents,vvint &queries) {
        int n=parents.size(), q=queries.size(), root=-1;
        vvint adjList(n);
        for(int i=0;i<n;i++){
            int u=parents[i], v=i;
            if(u==-1){
                root=v;
                continue;
            }
            adjList[u].push_back(v);
        }
        vvvint offlineQuery(n);
        for(int i=0;i<q;i++){
            int u=queries[i][0], x=queries[i][1];
            offlineQuery[u].push_back({x,i});
        }
        Trie t;
        vint res(q,-1);
        DFS(root,res,offlineQuery,adjList,t);
        return res;
    }
};

int main(){

return 0;
}