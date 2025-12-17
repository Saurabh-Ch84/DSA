#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using u_mi_u_mii = unordered_map<int,unordered_map<int,int>> ;

// Optimal
class Solution {
    const int MOD = 1e9+7;
public:
    int numberOfWays(string corridor) {
        int n=corridor.size(),seatCount=0;
        for(int i=0;i<n;i++){
            if(corridor[i]=='S')    
                seatCount++;
        }
        if(!seatCount || seatCount & 1) return 0;
        long long count=1;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(corridor[i]=='P') continue;
            if(q.size()==2){
                q.pop();
                int j=q.front();
                q.pop();
                count=(count*(i-j))%MOD;
            }
            q.push(i);
        }
        return (int)count;
    }
};

//Brute
class Solution {
    const int MOD=1e9+7;
    
	int recursionArr(int prev,int i,int n,int next,vi &prefix,vvi &dp){
		if(i>=n) return 1;
        if(dp[prev][i]!=-1) return dp[prev][i];
		int ans=0;
		for(int j=i;j<n;j++){
			if(prefix[j]-prev==2){
				int nextAns=recursionArr(prefix[j],j+1,n,next,prefix,dp);
				ans=(ans+nextAns) % MOD;
			}
		}
		return dp[prev][i]=ans;
	}
	
	int recursionMap(int prev,int i,int n,int next,vi &prefix,u_mi_u_mii &hashMap){
		if(i>=n) return 1;
        if(hashMap[prev].count(i)) return hashMap[prev][i];
		int ans=0;
		for(int j=i;j<n;j++){
			if(prefix[j]-prev==2){
				int nextAns=recursionMap(prefix[j],j+1,n,next,prefix,hashMap);
				ans=(ans+nextAns)%MOD;
			}
		}
		return hashMap[prev][i]=ans;
	}
	
public:
    int numberOfWays(string corridor) {
        int n=corridor.size();
        vi prefix(n,0);
        
        for(int i=0;i<n;i++)
        	prefix[i]=(i? prefix[i-1]:0) + (corridor[i]=='S'? 1:0);
        
        if(prefix[n-1]%2==1) return 0;
        if(prefix[n-1]==2) return 1;

        // vvi dp(prefix[n-1]+1,vi(n,-1));
        //return recursion(0,0,n,prefix[n-1],prefix,dp);

        unordered_map<int,unordered_map<int,int>> hashMap;
        return recursionMap(0,0,n,prefix[n-1],prefix,hashMap);
    }
};

int main(){

return 0;
}