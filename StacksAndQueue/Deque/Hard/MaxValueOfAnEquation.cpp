#include<bits/stdc++.h>
using namespace std;

class Solution {
    // using deque, optimal solution
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<int> dq;
        int n=points.size(), maxi=-1e9;
        for(int i=0;i<n;i++){ 
            int xJ=points[i][0], yJ=points[i][1];
            while(!dq.empty() && xJ-points[dq.front()][0]>k) // remove invalid points
                dq.pop_front();
            if(!dq.empty()){
                int xI=points[dq.front()][0], yI=points[dq.front()][1];
                maxi=max(maxi,yI+yJ+(xJ-xI));
            }
            while(!dq.empty() && points[dq.back()][1]-points[dq.back()][0]<=yJ-xJ) // maintain monotonicity
                dq.pop_back();
            dq.push_back(i);
        }
        return maxi;
    }
};

int main(){

return 0;
}