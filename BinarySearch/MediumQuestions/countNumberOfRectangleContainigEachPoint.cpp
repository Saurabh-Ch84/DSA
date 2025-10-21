#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    int lowerBound(vector<int> &arr,int low,int high,int target){
        int idx=high+1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(target<=arr[mid]){
                idx=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return idx;
    }
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> dp(101);

        for(vector<int> &rectangle: rectangles){
            int x=rectangle[0],y=rectangle[1];
            dp[y].push_back(x);
        }

        for(vector<int> &entry: dp) sort(begin(entry),end(entry));

        vector<int> ans;
        for(vector<int> &point: points){
            int x=point[0],y=point[1];
            int count=0;
            for(int i=y;i<101;i++){
                vector<int> &xVector=dp[i];
                int sz=xVector.size();
                int lb=lowerBound(xVector,0,sz-1,x);
                count+=sz-lb;
            }
            ans.push_back(count);
        }

        return ans;
    }
};

int main(){

return 0;
}