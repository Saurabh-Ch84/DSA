#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        int n=routes.size();
        unordered_map<int,vint> busStopToRouteMap;
        unordered_set<int> visitedRoutes;
        queue<int> q;

        for(int route=0;route<n;route++){
            int m=routes[route].size();
            for(int j=0;j<m;j++){
                int busStop=routes[route][j];
                busStopToRouteMap[busStop].push_back(route);
                if(busStop==source){
                    q.push(route);
                    visitedRoutes.insert(route);
                }
            }
        }
        int bus=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int route=q.front(); q.pop();
                for(int &busStop: routes[route]){
                    if(busStop==target) return bus;
                    for(int &nextRoute: busStopToRouteMap[busStop]){
                        if(visitedRoutes.count(nextRoute)) continue;
                        q.push(nextRoute);
                        visitedRoutes.insert(nextRoute);
                    }
                }
            }
            bus++;
        }
        return -1;
    }
};

int main(){

return 0;
}