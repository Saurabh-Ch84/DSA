#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
    bool areMutations(string &s1,string &s2){
        int mutations=0;
        for(int i=0;i<8;i++){
            if(s1[i]!=s2[i]) 
                mutations++;
            if(mutations>1) return false;
        }
        return (mutations==1);
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        unordered_set<int> visited;
        q.push(startGene);
        int moves=0, n=bank.size();

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string u=q.front(); q.pop();
                if(u==endGene) return moves;
                for(int i=0;i<n;i++){
                    if(areMutations(u,bank[i]) && !visited.count(i)){
                        visited.insert(i);
                        q.push(bank[i]);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};

int main(){

return 0;
}