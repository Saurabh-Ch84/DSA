#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> day;
public:
    Solution(int x=1e5){
        day.resize(x+1,0);
    }

    struct Comp{
        bool operator()(const vector<int> &a,const vector<int> &b){
            return a[1]<b[1];
        }
    };

    int maxEvents(vector<vector<int>>& events) {
        int n=events.size(),count=0;
        sort(begin(events),end(events),Comp());
        for(int i=0;i<n;i++){
            int startTime=events[i][0],endTime=events[i][1];
            for(int j=startTime;j<=endTime;j++){
                if(day[j]==0){
                    day[j]=1;
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};

class Solution2 {
    class DSU{
        vector<int> parent;
            public:
        DSU(int n=1e5){
            parent.resize(n+2);
            for(int i=0;i<n+2;i++)
                parent[i]=i;
        }

        int Find(int node){
            if(node==parent[node]) return node;
            return parent[node]=Find(parent[node]);
        }

        void Union(int u,int v){
            int rootU=Find(u);
            int rootV=Find(v);
            if(rootU!=rootV){
                parent[rootV]=rootU;
            }
        }
    };
public:
    struct Comp{
        bool operator()(const vector<int> &a,const vector<int> &b){
            return a[1]<b[1];
        }
    };

    int maxEvents(vector<vector<int>>& events) {
        int n=events.size(),count=0;
        sort(begin(events),end(events),Comp());
        DSU dsu(1e5);
        for(int i=0;i<n;i++){
            int startTime=events[i][0],endTime=events[i][1];
            int availDay=dsu.Find(startTime);
            if(availDay <= endTime){
                count++;
                dsu.Union(availDay+1,availDay);
            }
        }
        return count;
    }
};

int main(){

return 0;
}