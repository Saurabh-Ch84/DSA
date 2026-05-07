#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vlonglong=vector<long long>;
    using vvlonglong=vector<vlonglong>;
    const long long inf=1e12;
    long long recursion(int i,int j,int n,int m,vint &robot,vint &factoryArr,vvlonglong &dp){
        if(i>=n) return 0;
        if(j>=m) return inf;
        if(dp[i][j]!=-1) return dp[i][j];
        long long take=abs(robot[i]-factoryArr[j])+recursion(i+1,j+1,n,m,robot,factoryArr,dp);
        long long skip=0+recursion(i,j+1,n,m,robot,factoryArr,dp);
        return dp[i][j]=min(take,skip);
    }
public:
    long long minimumTotalDistance(vint &robot,vvint &factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        vint factoryArr;
        for(vint &f: factory){
            int pos=f[0],limit=f[1];
            for(int lim=0;lim<limit;lim++)
                factoryArr.push_back(pos);
        }
        int n=robot.size(), m=factoryArr.size();
        vvlonglong dp(n+1,vlonglong(m+1,-1));

        return recursion(0,0,n,m,robot,factoryArr,dp);
    }
};

int main(){

return 0;
}