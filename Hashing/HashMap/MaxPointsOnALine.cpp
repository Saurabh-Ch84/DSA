#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;

using vi=vector<int>;
using pii=pair<int,int>;
using memo_t1=map<pii,unordered_map<int,unordered_set<int>>>;
using memo_t2=map<vi,unordered_set<int>>;

class Solution {    
    int gcd(int a,int b){
        while(b){
            int t=b;
            b=a%b;
            a=t;
        }
        return a;
    }
    pii slope(vi &p,vi &q){
        int dx=p[0]-q[0], dy=p[1]-q[1];
        if(dx==0) return {1,0};
        if(dy==0) return {0,1};
        int g=gcd(abs(dx),abs(dy));
        dx=dx/g, dy=dy/g;
        if(dx<0){
            dy=-dy;
            dx=-dx;
        }
        return {dy,dx};
    }
    int lineID(vi &p,int dy,int dx){
        int x=p[0], y=p[1];
        return (y*dx-x*dy);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size(), maxi=1;
        memo_t1 memo;      
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pii m=slope(points[i],points[j]);
                int dy=m.first, dx=m.second;
                int cdx=lineID(points[i],dy,dx);
                memo[{dy,dx}][cdx].insert({i,j});
                maxi=max(maxi,(int)memo[{dy,dx}][cdx].size());
            }
        }
        return maxi;
    }
};


class Solution {    
    int gcd(int a,int b){
        while(b){
            int t=b;
            b=a%b;
            a=t;
        }
        return a;
    }
    pii slope(vi &p,vi &q){
        int dx=p[0]-q[0], dy=p[1]-q[1];
        if(dx==0) return {1,0};
        if(dy==0) return {0,1};
        int g=gcd(abs(dx),abs(dy));
        dx=dx/g, dy=dy/g;
        if(dx<0){
            dy=-dy;
            dx=-dx;
        }
        return {dy,dx};
    }
    int lineID(vi &p,int dy,int dx){
        int x=p[0], y=p[1];
        return (y*dx-x*dy);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size(), maxi=1;
        memo_t2 memo;      
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pii m=slope(points[i],points[j]);
                int dy=m.first, dx=m.second;
                int cdx=lineID(points[i],dy,dx);
                memo[{dy,dx,cdx}].insert({i,j});
                maxi=max(maxi,(int)memo[{dy,dx,cdx}].size());
            }
        }
        return maxi;
    }
};

int main(){

return 0;
}