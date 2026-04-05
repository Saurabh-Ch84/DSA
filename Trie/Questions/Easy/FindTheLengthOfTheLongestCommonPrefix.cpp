#include<iostream>
#include<vector>

using namespace std;
using vint=vector<int>;


class Solution {
    class Trie{
        Trie *child[10];

        void helper(int num,vint &temp){
            while(num){
                int d=num%10;
                temp.push_back(d);
                num=num/10;
            }
        }
            public:
        Trie(){
            for(int i=0;i<10;i++)
                child[i]=nullptr;
        }

        void insert(int num){
            Trie *current=this;
            vint temp;
            helper(num,temp);
            while(!temp.empty()){
                int d=temp.back();
                temp.pop_back();
                if(!current->child[d])
                    current->child[d]=new Trie();
                current=current->child[d];
            }
        }

        int search(int num){
            Trie *current=this;
            vint temp;
            helper(num,temp);
            int count=0;
            while(!temp.empty()){
                int d=temp.back();
                temp.pop_back();
                if(!current->child[d])
                    break;
                current=current->child[d];
                count++;
            }
            return count;
        }
    };
public:
    int longestCommonPrefix(vint &arr1,vint &arr2) {
        Trie t;
        for(int &num: arr1){
            t.insert(num);
        }
        int maxi=0;
        for(int &num: arr2){
            maxi=max(maxi,t.search(num));
        }
        return maxi;
    }
};

int main(){

return 0;
}