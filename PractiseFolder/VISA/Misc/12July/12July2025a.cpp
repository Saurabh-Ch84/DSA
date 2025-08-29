#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
'N' machines were given with their 'efficiency' and 'duration' and a formula was given that,
 Best Fit for 'K' machines=(sum of efficiency of 'K' machines) * (minimum of duration of 'K' machines). 
'K' was given, problem was to select 'K' machines such that 'Best fit for 'K' machines' is maximum.
*/

struct Machine {
    int efficiency;
    int duration;
};

class Solution {
    static bool comp(const Machine &a,const Machine &b){
        return a.duration>b.duration;
    }
public:
    long long maxBestFit(vector<Machine>& machines, int K) {
        sort(machines.begin(),machines.end(),comp);
        priority_queue<int ,vector<int>,greater<int>> pq;

        long long sumEfficiency=0,maxAns=0;
        for(const auto &machine:machines){
            pq.push(machine.efficiency);
            sumEfficiency+=machine.efficiency;
            if(pq.size()>K){
                sumEfficiency-=pq.top();
                pq.pop();
            }
            if(pq.size()==K)
                maxAns=max(maxAns,1LL*sumEfficiency*machine.duration);
        }
        return maxAns;
    }
};

int main() {
    Solution sol;
    vector<Machine> machines = {
        {10, 5}, {8, 3}, {7, 4}, {6, 2}
    };
    int K = 2;

    cout << "Maximum Best Fit: " << sol.maxBestFit(machines, K) << endl;
    return 0;
}
