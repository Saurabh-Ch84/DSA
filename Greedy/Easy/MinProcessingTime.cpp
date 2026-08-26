#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.rbegin(),tasks.rend());
        int n=processorTime.size(), time=0, offset=0;
        for(int i=0;i<n;i++){
            int cpu=processorTime[i];
            int maxTask=cpu+max({tasks[i+offset],tasks[i+1+offset],tasks[i+2+offset],tasks[i+3+offset]});
            time=max(time,maxTask);
            offset+=3;
        }   
        return time;
    }
};

int main(){

return 0;
}