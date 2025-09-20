#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(begin(players),end(players));
        sort(begin(trainers),end(trainers));
        int left=0,right=0,n=players.size(),m=trainers.size();
        int count=0;
        while(left<n && right<m){
            if(players[left]<=trainers[right]){
                left++;
                right++;
                count++;
            }
            else right++;
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> players={9,8,3,1,5,3,3,7,3,16};
    vector<int> trainers={6,2,9,0,5,0,0,8,7,3};

    cout<<s.matchPlayersAndTrainers(players,trainers);
return 0;
}