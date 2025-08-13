#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        long long waitingTime=0,totalWaitingTime=0;
        for(int i=1;i<bt.size();i++){
            waitingTime+=bt[i-1];
            totalWaitingTime+=waitingTime;
        }
        return totalWaitingTime/bt.size();
    }
};

int main(){

return 0;
}