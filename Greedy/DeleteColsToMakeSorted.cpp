#include<iostream>
#include<vector>

using namespace std;
using vb = vector<bool> ;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(), m=strs[0].size(), deletions=0;
        vb prevRowsSorted(n-1,false);
        for(int j=0;j<m;j++){
            bool mustDelete=false, allSorted=true;
            for(int i=0;i<n-1;i++){
                if(allSorted && strs[i][j]>=strs[i+1][j]) 
                    allSorted=false;
                if(!prevRowsSorted[i] && strs[i][j]>strs[i+1][j]){
                    mustDelete=true;
                    break;
                }
            }
            if(allSorted) break;
            if(mustDelete){
                deletions++;
                continue;
            }
            for(int i=0;i<n-1;i++){
                if(strs[i][j]<strs[i+1][j])
                    prevRowsSorted[i]=true;
            }
        }
        return deletions;
    }
};

int main(){

return 0;
}