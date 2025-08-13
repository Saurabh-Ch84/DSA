#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> res(n,-1);
        stack<int> mDStack;
        for(int i=n-1;i>-1;i--){
            while(!mDStack.empty() && arr[i]>=mDStack.top())
                mDStack.pop();
            if(!mDStack.empty())
                res[i]=mDStack.top();
            mDStack.push(arr[i]);
        }
        return res;
    }
};

int main(){

return 0;
}