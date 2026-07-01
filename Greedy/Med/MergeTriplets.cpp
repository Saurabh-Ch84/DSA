#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();
        vector<int> maxVal(3,0);
        for(int i=0;i<n;i++){
            if( triplets[i][0]<=target[0] &&
                triplets[i][1]<=target[1] &&
                triplets[i][2]<=target[2] ){
                    maxVal[0]=max(maxVal[0],triplets[i][0]);
                    maxVal[1]=max(maxVal[1],triplets[i][1]);
                    maxVal[2]=max(maxVal[2],triplets[i][2]);
               }
            if(maxVal==target) return true;
        }
        return false;
    }
};

int main(){

return 0;
}