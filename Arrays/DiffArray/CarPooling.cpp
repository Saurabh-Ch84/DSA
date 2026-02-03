#include<iostream>
#include<vector>
using namespace std;

using vi=vector<int>;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int lb=1e9,ub=0;
        for(vi &trip: trips){
            lb=min(lb,trip[1]);
            ub=max(ub,trip[2]);
        }
        int n=ub-lb+1;
        vi diffArr(n,0);
        for(vi &trip: trips){
            int c=trip[0], start=trip[1], end=trip[2];
            diffArr[start-lb]+=c;
            diffArr[end-lb]-=c;
        }
        for(int i=1;i<n-1;i++)
            diffArr[i]+=diffArr[i-1];
        for(int i=0;i<n;i++){
            if(diffArr[i]>capacity)
                return false;
        }
        return true;
    }
};

int main(){

return 0;
}