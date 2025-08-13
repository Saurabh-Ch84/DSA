#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows,{1});
        for(int i=0;i<numRows;i++){
            for(int j=1;j<=i;j++){
                int prev=ans[i].back();
                int curr=(prev*(i-j+1))/j;
                ans[i].push_back(curr);
            }
        }
        return ans;
    }
};

int main(){

return 0;
}