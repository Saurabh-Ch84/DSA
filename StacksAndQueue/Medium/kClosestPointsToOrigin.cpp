#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    struct Comp{
        bool operator()(const vector<int> &a,const vector<int> &b){
            long long distA=1LL*a[0]*a[0]+1LL*a[1]*a[1];
            long long distB=1LL*b[0]*b[0]+1LL*b[1]*b[1];
            return distA<distB;
        }
    };
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        sort(points.begin(),points.end(),Comp());
        
        vector<vector<int>> res;
        for (int i = 0; i < k; i++) res.push_back(points[i]);
        
        return res;
    }
};

using vi=vector<int> ;

class Solution2 {
    struct Comp{
        bool operator()(const vi &a,const vi &b) const{
            long long distA=1LL*a[0]*a[0]+1LL*a[1]*a[1];
            long long distB=1LL*b[0]*b[0]+1LL*b[1]*b[1];
            return distA<distB;
        }
    };
    
    long long distanceFromOrigin(int x,int y){
        return 1LL*x*x+1LL*y*y;
    }
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        priority_queue<vi,vector<vi>,Comp> pq;
        for(vi &point: points){
            int x=point[0],y=point[1];
            if(pq.size()<k) pq.push(point);
            else{
                long long dNew=distanceFromOrigin(x,y);
                vi top=pq.top();
                long long dTop=distanceFromOrigin(top[0],top[1]);
                if(dNew<dTop){
                    pq.pop();
                    pq.push(point);
                }
            }
        }
        
        vector<vi> res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        
        return res;
    }
};

int main(){

return 0;
}