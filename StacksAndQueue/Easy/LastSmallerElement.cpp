#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        // code here
        int n=arr.size();
        vector<int> res(n,-1);
        stack<int> mIStack;
        for(int i=0;i<n;i++){
            while(!mIStack.empty() && arr[i]<=mIStack.top())
                mIStack.pop();
            if(!mIStack.empty()) res[i]=mIStack.top();
            mIStack.push(arr[i]);
        }
        return res;
    }
};

int main(){

return 0;
}