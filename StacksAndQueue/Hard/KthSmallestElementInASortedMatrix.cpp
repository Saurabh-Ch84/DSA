#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
public:
    int kthSmallest(vvint &matrix, int k) {
        int n=matrix.size();
        priority_queue<vint,vvint,greater<vint>> pq;
        for(int i=0;i<n;i++)
            pq.push({matrix[i][0],i,0});

        int popCount=0, prev=-1;
        while(popCount<k){
            vint entry=pq.top(); pq.pop();
            popCount++;
            int val=entry[0], row=entry[1], col=entry[2];
            if(col<n-1){
                col++;
                pq.push({matrix[row][col],row,col});
            }
            prev=val;
        }
        return prev;
    }
};

int main(){

return 0;
}