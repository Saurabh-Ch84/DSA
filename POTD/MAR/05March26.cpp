#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution1 {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<int,int> hashMap;
        int n=s.size(), left=0, right=0, maxi=-1;
        while(right<n){
            hashMap[s[right]]++;
            while(hashMap.size()>k){
                hashMap[s[left]]--;
                if(!hashMap[s[left]])
                    hashMap.erase(s[left]);
                left++;
            }
            if(hashMap.size()==k) maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};

class Solution2 {
public:
    int minOperations(string s) {
        int count=0, n=s.size();
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                s[i]='0'+('1'-s[i]);
                count++;
            }
        }
        return min(count,n-count);
    }
};

int main(){

return 0;
}