#include<iostream>
#include<vector>
using namespace std;

class Solution {
    class Trie{
            public:
        int count;
        Trie* child[2];
        Trie(){
            count=0;
            child[0]=child[1]=nullptr;
        }
        void insert(int num){
            Trie* current=this;
            for(int i=31;i>=0;i--){
                int bit=(num>>i) & 1;
                if(!current->child[bit])
                    current->child[bit]=new Trie();
                current=current->child[bit];
                current->count++;
            }
        }
        int query(int num, int k){
            Trie* current = this;
            int ans = 0;
            for(int i = 31; i >= 0; i--){
                int bitNum = (num >> i) & 1;
                int bitK = (k >> i) & 1;
                if(bitK){
                    if(current->child[bitNum])
                        ans+=current->child[bitNum]->count;
                    if(current->child[bitNum^1])
                        current=current->child[bitNum^1];
                    else break;
                } 
                else{
                    if(current->child[bitNum])
                        current=current->child[bitNum];
                    else break;
                }
            }
            return ans;
        }
    };
  public:
    int cntPairs(vector<int>& arr, int k) {
        // code here
        Trie *trie=new Trie();
        int ans=0;
        for(int &num: arr){
            ans+=trie->query(num,k);
            trie->insert(num);
        }
        return ans;
    }
};


int main(){
    
return 0;
}