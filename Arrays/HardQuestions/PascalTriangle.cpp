#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    //print the Pascal's Triangle
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows,{1});
        for(int i=0;i<numRows;i++)
        {
            for(int j=1;j<=i;j++)
            {
                int prev=ans[i].back();
                int curr=((i-j+1)*prev)/j;
                ans[i].push_back(curr);
            }
        }
        return ans;
    }
    //Compute nCr
    int nCr(int n,int r) {
        int ans=1;
        for(int i=1;i<=r;i++)
            ans=(ans*(n-i+1))/i;
        return ans;
    }

    //nth row in Pascal's triangle
    vector<int> pascalRow(int n){
        vector<int> res(1,1);
        for(int i=1;i<=n;i++){
            int newVal=(res.back()*(n-i+1))/i;
            res.push_back(newVal);
        }
        return res;
    }
};

int main(){

return 0;
}