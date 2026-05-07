#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    using vint=vector<int>;
    using vvint=vector<vint>;
    const int mod=1e9+7;
    int binaryExpo(int base,int p){
        base=base%mod;
        long long res=1;
        while(p){
            if(p & 1) res=(res*base)%mod;
            p=p/2;
            base=(1LL*base*base)%mod;
        }
        return res%mod;
    }
    struct Comp{
        bool operator()(const vint &a,const vint &b){
            int zeroA=a[1], zeroB=b[1];
            int oneA=a[0], oneB=b[0];
            if(!zeroA && !zeroB) return oneA>oneB;
            else if(!zeroA) return true;
            else if(!zeroB) return false;
            else if(oneA==oneB) return zeroA<zeroB;
            return oneA>oneB;
        }
    };
public:
    int maxValue(vint &nums1,vint &nums0) {
        int n=nums1.size(), totalBits=0;
        vvint segments;
        for(int i=0;i<n;i++){
            int ones=nums1[i], zeros=nums0[i];
            segments.push_back({ones,zeros});
            totalBits+=ones+zeros;
        }
        sort(segments.begin(),segments.end(),Comp());
        int num=0;
        for(int i=0;i<n;i++){
            int ones=segments[i][0],zeros=segments[i][1];
            int k=ones+zeros;
            if(ones){
                long high=binaryExpo(2,totalBits);
                long low=binaryExpo(2,totalBits-ones);
                long sumOfPowers=(high-low+mod)%mod;
                num=(num+sumOfPowers)%mod;
            }
            totalBits-=k;
        }
        return num%mod;
    }
};

int main(){

return 0;
}