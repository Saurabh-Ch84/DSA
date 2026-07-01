#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalGas=0,totalCost=0;
        for(int i=0;i<n;i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
        }
        if(totalCost>totalGas) return -1;
        int tank=0,idx=0;
        for(int i=0;i<n;i++){
            tank=tank+gas[i]-cost[i];
            if(tank<0){
                idx=i+1;
                tank=0;
            }
        }
        return idx;
    }
};

int main(){

return 0;
}