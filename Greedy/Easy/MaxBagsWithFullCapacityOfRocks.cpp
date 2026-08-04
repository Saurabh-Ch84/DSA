#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    struct Comp{
        bool operator()(const vint &a,const vint &b){
            int dA=a[0]-a[1], dB=b[0]-b[1];
            if(dA!=dB) return dA<dB;
            return a<b;
        }
    };
public:
    int maximumBags1(vint &capacity,vint &rocks, int additionalRocks) {
        int n=capacity.size();
        vvint arr(n);
        for(int i=0;i<n;i++)
            arr[i]={capacity[i],rocks[i]};
        sort(arr.begin(),arr.end(),Comp());
        int count=0;
        for(int i=0;i<n;i++){
            int d=arr[i][0]-arr[i][1];
            if(d>additionalRocks) break;
            additionalRocks-=d;
            count++;
        }
        return count;
    }
    // optimized version of maximumBags1
    int maximumBags2(vint &capacity,vint &rocks, int additionalRocks) {
        int n=capacity.size();
        vint diff(n);
        for(int i=0;i<n;i++)
            diff[i]=capacity[i]-rocks[i];
        sort(diff.begin(),diff.end());
        int count=0;
        for(int i=0;i<n;i++){
            if(diff[i]>additionalRocks) break;
            additionalRocks-=diff[i];
            count++;
        }
        return count;
    }
};

int main(){

return 0;
}