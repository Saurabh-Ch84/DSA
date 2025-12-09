#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        unordered_map<int,vector<int>> hashMap;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                hashMap[j-i].push_back(mat[i][j]);
            }
        }
        for(auto &p: hashMap){
            vector<int> &temp=p.second;
            sort(temp.rbegin(),temp.rend());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]=hashMap[j-i].back();
                hashMap[j-i].pop_back();
            }
        }
        return mat;
    }
};

int main(){

return 0;
}