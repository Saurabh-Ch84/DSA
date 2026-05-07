#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
public:
    int minOperations(vvint &grid,int x) {
        int m=grid.size(), n=grid[0].size();

        vint arr;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                arr.push_back(grid[i][j]);
        }

        sort(arr.begin(),arr.end());
        int count=0, median=arr[arr.size()/2];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int diff=abs(grid[i][j]-median);
                if(diff%x==0) count+=diff/x;
                else return -1;
            }
        }
        return count;
    }
};

class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int n=s.size(), right=0, left=0, maxi=0, maxF=0;
        vector<int> arr(26,0);
        
        while(right<n){
            arr[s[right]-'A']++;
            maxF=max(maxF,arr[s[right]-'A']);
            int ops=(right-left+1)-maxF;
            if(ops>k){
                arr[s[left]-'A']--;
                left++;
            }
            else maxi=max(maxi,ops+maxF);
            right++;
        }
        return maxi;
    }
};

int main(){

return 0;
}