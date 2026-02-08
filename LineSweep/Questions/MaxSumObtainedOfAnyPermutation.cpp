#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using vi=vector<int>;
using vvi=vector<vi>;

class Solution{
    const int mod=1e9+7;
public:
    int maxSumRangeQuery(vi &nums,vvi &requests) {
        int n=nums.size();
        vi freqArr(n+1,0);
        for(vi &req: requests){
            int start=req[0], end=req[1];
            freqArr[start]++;
            freqArr[end+1]--;
        }

        for(int i=1;i<=n;i++)
            freqArr[i]=freqArr[i]+freqArr[i-1];

        sort(freqArr.begin(),freqArr.end());
        sort(nums.begin(),nums.end());

        long long sum=0;
        while(!nums.empty() && !freqArr.empty() && freqArr.back()>0){
            int maxf=freqArr.back(); freqArr.pop_back();
            int maxNum=nums.back(); nums.pop_back();
            sum=(sum+1LL*maxf*maxNum)%mod;
        }
        return (int)sum;
    }
};

int main(){

return 0;
}