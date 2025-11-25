#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<vector<int>> arr;
        for(int i=0;i<n;i++)
            arr.push_back({position[i],speed[i]});
        
        sort(arr.begin(),arr.end());

        stack<double> mnst;
        for(vector<int> &p: arr){
            int pos=p[0],s=p[1];
            double time=(target-pos)/(s*1.0);
            while(!mnst.empty() && mnst.top()<=time)
                mnst.pop();
            mnst.push(time);
        }
        return mnst.size();
    }
};

class Solution2 {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> cars;
        
        for(int i=0; i<n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.rbegin(), cars.rend());
        
        int fleets = 0;
        double prevTime = 0.0;
        for(auto &car : cars) {
            double currTime=car.second;
            if(currTime > prevTime) {
                fleets++;
                prevTime=currTime;
            }
        }
        
        return fleets;
    }
};



int main(){

return 0;
}