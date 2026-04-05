#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

using vint=vector<int>;
class Solution1 {
    bool check(long long mid,vint &workerTimes,int mountainHeight){    
        for(int &workerTime: workerTimes){
            int low=0, high=mountainHeight, ans=0;
            while(low<=high){
                int midH=low+(high-low)/2;
                long long t=(1LL*midH*(midH+1))/2*workerTime;
                if(t<=mid){
                    ans=midH;
                    low=midH+1;
                }
                else high=midH-1;
            }
            mountainHeight-=ans;
            if(mountainHeight<=0) return true;
        }
        return (mountainHeight<=0);
    }
public:
    long long minNumberOfSeconds(int mountainHeight,vint &workerTimes) {
        sort(workerTimes.begin(),workerTimes.end());
        long long low=1, high=(1LL*mountainHeight*(mountainHeight+1))/2*workerTimes.back();
        
        long long ans=-1;
        while(low<=high){
            long long mid=low+(high-low)/2;
            bool resp=check(mid,workerTimes,mountainHeight);
            if(resp){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};

//Optimal.
using vint=vector<int>;
class Solution {
    bool check(long long mid,vint &workerTimes,int mountainHeight){    
        for(int &workerTime: workerTimes){
            int ans=(-1+sqrt(1+(8.0*mid)/workerTime))/2;
            mountainHeight-=ans;
            if(mountainHeight<=0) return true;
        }
        return (mountainHeight<=0);
    }
public:
    long long minNumberOfSeconds(int mountainHeight,vint &workerTimes) {
        sort(workerTimes.begin(),workerTimes.end());
        long long low=1, high=(1LL*mountainHeight*(mountainHeight+1))/2*workerTimes.back();
        
        long long ans=-1;
        while(low<=high){
            long long mid=low+(high-low)/2;
            bool resp=check(mid,workerTimes,mountainHeight);
            if(resp){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};

using vstr=vector<string>;
class Solution2 {
    void recursion(vstr &result,string temp,string &s,int i,int n,int seg){
        if(i==n){
            if(seg==4) result.push_back(temp);
            return ;
        }
        if(i) temp.push_back('.');
        int octet=0;
        for(int j=i;j<n;j++){
            octet=octet*10+(s[j]-'0');
            if(octet<256 && seg<4)
                recursion(result,temp+s.substr(i,j-i+1),s,j+1,n,seg+1);
            if(octet==0 || octet>=256) break;
        }
    }
  public:
    vector<string> generateIp(string &s) {
        // code here
        vstr result;
        string temp;
        recursion(result,temp,s,0,s.size(),0);
        return result;
    }
};


int main(){

return 0;
}