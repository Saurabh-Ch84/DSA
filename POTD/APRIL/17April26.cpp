#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    int getReverse(int num){
        int num_=0;
        while(num){
            int d=num%10;
            num=num/10;
            num_=num_*10+d;
        }
        return num_;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size(), mini=n;
        unordered_map<int,int> hashMap;
        for(int i=n-1;i>=0;i--){
            int num=nums[i];
            int revNum=getReverse(num);
            if(hashMap.count(revNum))
                mini=min(mini,abs(hashMap[revNum]-i));
            hashMap[num]=i;
        }
        return (mini==n ? -1: mini);
    }
};

class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        vector<int> v(26,0);
        for(auto &ch: s){
            v[ch-'a']++;
        }
        bool oddFreq=0;
        for(int i=0;i<26;i++){
            if(oddFreq && v[i]%2==1) return false;
            else if(!oddFreq && v[i]%2==1) oddFreq=true;
        }
        return true;
    }
};

int main(){

return 0;
}