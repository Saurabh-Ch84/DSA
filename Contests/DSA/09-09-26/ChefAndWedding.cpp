#include<bits/stdc++.h>
using namespace std;

class Solution{
    vector<vector<int>> dp;
    int getNewArgumentingFamilyMembers(int i,int j,vector<int> &family){
        auto left=lower_bound(family.begin(),family.end(),i);
        auto right=lower_bound(family.begin(),family.end(),j);
        int total=right-left+1, count=0;
        if(total==2) count=2;
        else if(total>2) count=1;
        return count;
    }
    int recursion(int i,int j,int N,int K,vector<int> &families,vector<vector<int>> &familyMembersIndices){
        if(j==N) return 0;
        if(dp[i+1][j]!=-1) return dp[i+1][j];
        int takeNewTable=1e8,skipNewTable=1e8;
        if(i!=-1){
            vector<int> &family=familyMembersIndices[families[j]];
            skipNewTable=getNewArgumentingFamilyMembers(i,j,family)+recursion(i,j+1,N,K,families,familyMembersIndices);
        }
        takeNewTable=K+recursion(j,j+1,N,K,families,familyMembersIndices);
        return dp[i+1][j]=min(skipNewTable,takeNewTable);
    }
        public:
    int solve(int N,int K,vector<int> &families,int bound){
        vector<vector<int>> familyMembersIndices(bound+1);
        for(int i=0;i<N;i++){
            int family=families[i];
            familyMembersIndices[family].push_back(i);
        }
        dp.assign(N+2,vector<int>(N+1,-1));
        return recursion(-1,0,N,K,families,familyMembersIndices);
    }    
};

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int N,K;
        cin>>N>>K;
        vector<int> families(N,-1);
        int bound=0;
        Solution s;
        for(int j=0;j<N;j++){
            cin>>families[j];
            bound=max(bound,families[j]);
        }
        cout<<s.solve(N,K,families,bound)<<endl;    
    }
return 0;
}