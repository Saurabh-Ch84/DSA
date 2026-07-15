#include<bits/stdc++.h>
using namespace std;

class Solution1 {
  public:
    int countSubstring(string& s) {
        // Code Here
        int n=s.length();
        long long ans=0, validLeftPoints=0, cumSum=0;
        unordered_map<int,int> hashMap;
        hashMap[0]=1;
        
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                validLeftPoints+=hashMap[cumSum];
                cumSum++;
            }
            else{
                cumSum--;
                validLeftPoints-=hashMap[cumSum];
            }
            hashMap[cumSum]++;
            ans+=validLeftPoints;
        }
        return ans;
    }
};

class Solution2 {
  public:
    int countSubstring(string& s) {
        // Code Here
        int ans = 0;
        int sum = 0;
        int curr = 0;
        unordered_map<int,int> mp;
        mp[0]++;
        for(char ch:s)
        {
            if(ch=='0')
            {
                sum--;
            }
            else{
                sum++;
            }
            if(ch=='0')
            {
                curr-= mp[sum];
            }
            else{
                curr+=mp[sum-1];
            }
            ans += curr;
            mp[sum]++;
        }
        return ans;
    }
};

int main(){

return 0;
}