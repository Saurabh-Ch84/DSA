#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool checkBlock(vector<int> &helperArray,int offset){
        vector<int> copy=helperArray;
        for(int i=offset;i<offset+4;i++){
            if(copy[i]) return false;
            copy[i]=1;
        }
        // save the changes to the original helperArray.
        helperArray=copy;
        return true;
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m=reservedSeats.size();
        unordered_map<int,vector<int>> hashMap;
        for(auto &reservedSeat: reservedSeats){
            int r=reservedSeat[0], s=reservedSeat[1];
            hashMap[r].push_back(s);
        }
        int total=0;
        int freeRows=n-hashMap.size();
        total=total+freeRows*2; // each free row can accommodate 2 families.
        for(auto &p: hashMap){
            vector<int> &seats=p.second, helperArr(11,0);
            int k=seats.size();
            for(int i=0;i<k;i++){
                int j=seats[i];
                helperArr[j]=1;
            }
            // try greedily to check if we can allocate 2 families in this row.
            int count=checkBlock(helperArr,2)+checkBlock(helperArr,6)+checkBlock(helperArr,4);
            total+=count;
        }
        return total;
    }
};

int main(){

return 0;
}