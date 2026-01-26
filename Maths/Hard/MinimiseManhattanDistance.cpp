#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n=points.size();

        vector<int> xPlusY, xMinusY;
        for(vector<int> &point: points){
            int x=point[0], y=point[1];
            xPlusY.push_back(x+y);
            xMinusY.push_back(x-y);
        }

        sort(xPlusY.begin(),xPlusY.end());
        sort(xMinusY.begin(),xMinusY.end());

        int ans=INT_MAX; 
        for(int i=0;i<n;i++){
            int x=points[i][0], y=points[i][1];
            int currXPlusY=x+y, currXMinusY=x-y;

            int maxXPlusY=(xPlusY[n-1]==currXPlusY ? xPlusY[n-2]:xPlusY[n-1]);
            int minXPlusY=(xPlusY[0]==currXPlusY ? xPlusY[1]:xPlusY[0]);

            int maxXMinusY=(xMinusY[n-1]==currXMinusY ? xMinusY[n-2]:xMinusY[n-1]);
            int minXMinusY=(xMinusY[0]==currXMinusY ? xMinusY[1]:xMinusY[0]);

            int val=max((maxXPlusY-minXPlusY),(maxXMinusY-minXMinusY));
            ans=min(ans,val);
        }
        return ans;
    }
};

int main(){

return 0;
}