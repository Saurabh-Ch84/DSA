#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

using vi = vector<int> ;
using pii = pair<int,int> ;

class Solution {
    int gcd(int a,int b){
        while(b){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }

    pii slope(vi &P,vi &Q){
        int x1=P[0],y1=P[1];
        int x2=Q[0],y2=Q[1];
        int dx=x2-x1,dy=y2-y1;
        if(dx==0) return {1,0};
        if(dy==0) return {0,1};
        int common=gcd(abs(dx),abs(dy));
        dx=dx/common;
        dy=dy/common;
        if(dx<0){
            dy=-dy;
            dx=-dx;
        }
        return {dy,dx};
    }
    
    int LineID(vi &points,int dy,int dx){
        int x=points[0],y=points[1];
        return y*dx-x*dy;
    }

public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();
        // (dy,dx)->(C->freq);
        map<pii,unordered_map<long long,int>> hashMap;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pii m=slope(points[i],points[j]);
                int dy=m.first,dx=m.second;
                int c=LineID(points[i],dy,dx);
                //lines are stored.
                hashMap[{dy,dx}][c]++;
            }
        }
        int totalCount=0;
        for(auto &p: hashMap){
            unordered_map<long long,int> &tempMap=p.second;
            int prev=0;
            for(auto &q: tempMap){
                int curr=q.second;
                totalCount+=curr*prev;
                prev=(prev+curr);
            }
        }
        return totalCount;
    }
};

int main(){

return 0;
}