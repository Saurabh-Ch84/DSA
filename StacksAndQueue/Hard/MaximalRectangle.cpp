#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
    int largestRectangleInHistogram(vector<int> &heights,int n){
        stack<int> helperStack;
        int maxArea=0;
        for(int i=0;i<n;i++){
            while(!helperStack.empty() && heights[i]<heights[helperStack.top()]){
                int nse=i,idx=helperStack.top();
                helperStack.pop();
                int height=heights[idx];
                int pse=(helperStack.empty())?-1:helperStack.top();
                int area=height*(nse-pse-1);
                maxArea=max(maxArea,area);                
            }
            helperStack.push(i);
        }
        while(!helperStack.empty()){
            int nse=n,idx=helperStack.top();
            helperStack.pop();
            int height=heights[idx];
            int pse=(helperStack.empty())?-1:helperStack.top();
            int area=height*(nse-pse-1);
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea=0,n=matrix[0].size();
        vector<int> tempHeight(n,0);
        for(vector<char> &arr:matrix){
            for(int i=0;i<n;i++){
                if(arr[i]=='1') tempHeight[i]+=1;
                else tempHeight[i]=0;
            }
            maxArea=max(maxArea,largestRectangleInHistogram(tempHeight,n));
        }
        return maxArea;
    }
};

int main(){

return 0;
}