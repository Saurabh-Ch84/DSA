#include<iostream>
#include<bits/stdc++.h>
using namespace std;

using v = vector<int>;

class Solution {
    struct Compare{
        bool operator()(const v &a,const v &b){
            double gainA=(double)(a[0]+1)/(a[1]+1)-(double)(a[0])/(a[1]);
            double gainB=(double)(b[0]+1)/(b[1]+1)-(double)(b[0])/(b[1]);
            return gainA<gainB;
        }
    };
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<v,vector<v>,Compare> pq(classes.begin(),classes.end());
        for(int i=0;i<extraStudents;i++){
            v u=pq.top();
            pq.pop();
            u[0]++,u[1]++;
            pq.push(u);
        }
        double ans=0.0;
        while(!pq.empty()){
            v u=pq.top();
            pq.pop();
            ans+=(double)u[0]/(u[1]);
        }
        ans/=n;
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> classes={{1,2},{3,5},{2,2}};
    int extraStudents=2;
    cout<<s.maxAverageRatio(classes,extraStudents);
return 0;
}