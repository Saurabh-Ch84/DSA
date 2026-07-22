#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int diagonalSum(vector<vector<int>>& fruits,int n){
        int fruitSum=0;
        for(int i=0;i<n;i++){
            fruitSum+=fruits[i][i];
        }
        return fruitSum;
    }

    bool isValid(int i,int j,int n){
        return (i>=0 && i<n && j>=0 && j<n);
    }
    
    int memoization(vector<vector<int>>& fruits,vector<int>& d,vector<int>& d_,int i,
                  int j,int n,bool topRightChild,vector<vector<int>> &dp)
    {
        if(i==n-1 && j==n-1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(topRightChild && i>=j){
            return -1;
        }
        else if(!topRightChild && i<=j){
            return -1;
        }
        
        int maxfruits=0,currentFruit=fruits[i][j];
        for(int k=0;k<3;k++){
            int i_=i+d[k],j_=j+d_[k];
            if(!isValid(i_,j_,n)) continue;
            int next= memoization(fruits,d,d_,i_,j_,n,topRightChild,dp);
            if(next==-1) continue;
            int fruitSum=currentFruit+next;
            maxfruits=max(maxfruits,fruitSum);
        }

        return dp[i][j]=maxfruits;
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        int child1= diagonalSum(fruits,n);
        
        vector<int> d={1,1,1},d_={-1,0,1};
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int child2= memoization(fruits,d,d_,0,n-1,n,true,dp);

        dp=vector<vector<int>>(n,vector<int>(n,-1));
        int child3= memoization(fruits,d_,d,n-1,0,n,false,dp);
        
        int totalFruits=child1+child2+child3;
        return totalFruits;
    }
};

int main(){
    Solution s;
    vector<vector<int>> fruits={{9,8,3,1},{5,3,3,7},{3,6,6,2},{9,0,5,0}};
    cout<<s.maxCollectedFruits(fruits)<<endl;
return 0;
}