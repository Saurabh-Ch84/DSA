#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int> histogram(m,0);
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]) histogram[j]+=1;
                else histogram[j]=0;
            }
            stack<vector<int>> s; //{height,index,prev_count}
            s.push({-1,-1,0});
            for(int j=0;j<m;j++){
                while(s.top()[0]>=histogram[j]) s.pop();
                int curr_count=histogram[j]*(j-s.top()[1]);
                curr_count+=s.top()[2];
                count+=curr_count;
                s.push({histogram[j],j,curr_count});
            }
        }
        return count;
    }
};

int main(){
    Solution s;

    vector<vector<int>> mat = {
    {1,0,1},
    {1,1,0},
    {1,1,0}
    };

    cout<<s.numSubmat(mat);
return 0;
}