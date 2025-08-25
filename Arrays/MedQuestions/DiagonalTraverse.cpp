#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> newMat(n+m-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int idx=i+j;
                newMat[idx].push_back(mat[i][j]);
            }
        }
        vector<int> res;
        for(int i=0;i<n+m-1;i++){
            if(i%2==0) res.insert(res.end(),newMat[i].rbegin(),newMat[i].rend());
            else res.insert(res.end(),newMat[i].begin(),newMat[i].end());
        }
        return res;
    }
};

void print(vector<vector<int>> &nums){
    for(vector<int> &row:nums){
        for(int &num:row){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void print(vector<int> nums){
    for(int &num:nums){
        cout<<num<<" ";
    }
    cout<<endl;
}

int main(){
    Solution s;
    vector<vector<int>> nums={{1,7,8},{3,45,7},{23,5,0}};
    print(nums);
    print(s.findDiagonalOrder(nums));
return 0;
}