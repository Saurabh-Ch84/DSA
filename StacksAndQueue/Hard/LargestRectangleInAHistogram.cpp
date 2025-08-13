#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//optimal solution
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> s;
        int maxArea=0;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && heights[i]<heights[s.top()])
            {
                int nse=i;
                int indx=s.top();
                s.pop();
                int height=heights[indx];
                int pse=(s.empty())?-1:s.top();
                int area=height*(nse-pse-1);
                maxArea=max(maxArea,area);
            }
            s.push(i);
        }
        //clean leftovers
        while(!s.empty()){
            int nse=n;
            int indx=s.top();
            s.pop();
            int height=heights[indx];
            int pse=(s.empty())?-1:s.top();
            int area=height*(nse-pse-1);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};

//better solution
class Solution1 {
    void getNextSmallerElement(vector<int> &heights,vector<int> &nse,int n){
        stack<int> mIStack;
        for(int i=n-1;i>-1;i--){
            while(!mIStack.empty() && heights[i]<=heights[mIStack.top()]) mIStack.pop();
            if(!mIStack.empty()) nse[i]=mIStack.top();
            mIStack.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        
        vector<int> nextSmaller(n,n);
        vector<int> prevSmaller(n,-1);
        getNextSmallerElement(heights,nextSmaller,n);
        stack<int> mIStack;
        long long maxArea=0;
        for(int i=0;i<n;i++){
            while(!mIStack.empty() && heights[i]<=heights[mIStack.top()]) mIStack.pop();
            if(!mIStack.empty()) prevSmaller[i]=mIStack.top();
            mIStack.push(i);
            int width=nextSmaller[i]-prevSmaller[i]-1;
            long long area=1LL*heights[i]*width;
            maxArea=max(maxArea,area);
        }
        return (int)maxArea;
    }
};

int main(){

return 0;
}