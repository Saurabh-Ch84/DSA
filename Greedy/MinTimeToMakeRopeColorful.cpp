#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length(),ptr=0;
        int prev=0,time=0;

        while(ptr<n){
            if(ptr>0 && colors[ptr]!=colors[ptr-1]) prev=0;
            int curr=neededTime[ptr++];
            time+=min(prev,curr);
            prev=max(prev,curr);
        }

        return time;
    }
};

int main(){

return 0;
}