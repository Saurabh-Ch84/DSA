#include<iostream>
using namespace std;

//Optimal
class Solution {
public:
    int minSteps(int n) {
        int ans=0;
        for(int d=2;d<=n;d++){
            while(n%d==0){
                ans+=d;
                n=n/d;
            }
        }
        return ans;
    }
};

//Brute
class Solution1 {
    const int INF=1e6;
    int recursion(int i,int n,int lc){
        if(i==n) return 0;
        if(i>n) return INF;
        int copy=INF,paste=INF;
        if(i!=lc) copy=1+recursion(i,n,i);
        if(lc) paste=1+recursion(i+lc,n,lc);
        return min(copy,paste);
    }
public:
    int minSteps(int n) {
        return recursion(1,n,0);
    }
};

int main(){

return 0;
}