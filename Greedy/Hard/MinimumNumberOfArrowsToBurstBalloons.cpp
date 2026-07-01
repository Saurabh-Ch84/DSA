#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int count=0, n=points.size();
        for(int i=0;i<n;i++){
            if(i && points[i][0]>=points[i-1][0] && points[i][0]<=points[i-1][1])
                points[i][1]=min(points[i][1],points[i-1][1]);
            else count++;
        }
        return count;
    }
};

int main(){

return 0;
}