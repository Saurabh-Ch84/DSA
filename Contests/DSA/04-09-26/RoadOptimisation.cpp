#include<bits/stdc++.h>
using namespace std;

using vint=vector<int>;
using vvint=vector<vint>;
using vvvint=vector<vvint>;
/*
        C. Road Optimization
    time limit per test 3 seconds
    memory limit per test 128 megabytes

    The Government of Mars is not only interested in optimizing space flights, but also wants to improve the road system of the planet.
    One of the most important highways of Mars connects Olymp City and Kstolop, the capital of Cydonia. 
    In this problem, we only consider the way from Kstolop to Olymp City, but not the reverse path (i. e. the path from Olymp City to Kstolop).

    The road from Kstolop to Olymp City is ℓ kilometers long. Each point of the road has a coordinate x(0≤x≤ℓ), 
    which is equal to the distance from Kstolop in kilometers. So, Kstolop is located in the point with coordinate 0, and Olymp City 
    is located in the point with coordinate ℓ.

There are n signs along the road, i-th of which sets a speed limit ai. This limit means that the next kilometer must be passed in ai
 minutes and is active until you encounter the next along the road. 
 There is a road sign at the start of the road (i. e. in the point with coordinate 0), which sets the initial speed limit.

If you know the location of all the signs, it's not hard to calculate how much time it takes to drive from Kstolop to Olymp City. Consider an example:

Here, you need to drive the first three kilometers in five minutes each, then one kilometer in eight minutes, then four kilometers in three minutes each, and finally the last two kilometers must be passed in six minutes each. Total time is 3⋅5+1⋅8+4⋅3+2⋅6=47
 minutes.

To optimize the road traffic, the Government of Mars decided to remove no more than k
 road signs. It cannot remove the sign at the start of the road, otherwise, there will be no limit at the start. By removing these signs, the Government also wants to make the time needed to drive from Kstolop to Olymp City as small as possible.

The largest industrial enterprises are located in Cydonia, so it's the priority task to optimize the road traffic from Olymp City. So, the Government of Mars wants you to remove the signs in the way described above.

Input
The first line contains three integers n, ℓ, k(1≤n≤500, 1≤ℓ≤1e5, 0≤k≤n−1), 
the amount of signs on the road, the distance between the cities and the maximal number of signs you may remove.

The second line contains n integers di (d1=0, d[i]<d[i+1], 0≤ di ≤ℓ−1) — coordinates of all signs.

The third line contains n integers ai (1≤ai≤1e4) — speed limits.

Output Print a single integer — minimal possible time to drive from Kstolop to Olymp City in minutes, if you remove no more than k road signs.
*/
int inf=1e7;

int recursion(int p,int i,int n,int k,int l,vint &d,vint &a,vvvint &dp){
    if(i==n) return 0;
    if(dp[p][i][k]!=-1) return dp[p][i][k];
    int skip=inf, take=inf;
    int distance=(i+1<n? d[i+1]-d[i]:l-d[i]);
    if(k && i){
        int prevSpeedLimit=a[p];
        skip=(distance*prevSpeedLimit)+recursion(p,i+1,n,k-1,l,d,a,dp);
    }
    int currSpeedLimit=a[i];
    take=(distance*currSpeedLimit)+recursion(i,i+1,n,k,l,d,a,dp);
    return dp[p][i][k]=min(skip,take);
}

int solve(int n,int l,int k,vint &d,vint &a){
    vvvint dp(n+1,vvint(n+1,vint(k+1,-1)));
    return recursion(0,0,n,k,l,d,a,dp);
}

int main(){
    // int n, l, k;
    // cin>>n>>l>>k;
    // vint d(n);
    // for(int i=0;i<n;i++)
    //     cin>>d[i];
    // vint a(n);
    // for(int i=0;i<n;i++)
    //     cin>>a[i];
    // cout<<solve(n,l,k,d,a);

    // Sample 1
    // Input:
    // 4 10 0
    // 0 3 4 8
    // 5 8 3 6
    {
        int n = 4, l = 10, k = 0;
        vint d = {0, 3, 4, 8};
        vint a = {5, 8, 3, 6};
        cout << "Sample 1 Output: " << solve(n, l, k, d, a) << endl; // Expected: 47
    }

    // Sample 2
    // Input:
    // 4 10 2
    // 0 3 4 8
    // 5 8 3 6
    {
        int n = 4, l = 10, k = 2;
        vint d = {0, 3, 4, 8};
        vint a = {5, 8, 3, 6};
        cout << "Sample 2 Output: " << solve(n, l, k, d, a) << endl; // Expected: 38
    }
return 0;
}