#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// Most Optimal Solution,
class Solution1 {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int left=0,right=0,ans=-1,n=s.length();
        unordered_map<char,int> freqMap;
        while(right<n){
            freqMap[s[right]]++;
            while(freqMap.size()>k)
            {
                freqMap[s[left]]--;
                if(freqMap[s[left]]==0) 
                    freqMap.erase(s[left]);
                left++;
            }
            if(freqMap.size()==k) ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};


//My solution. better solution
class Solution2 {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int left=0,right=0,ans=-1,n=s.length();
        unordered_map<char,int> lastOccMap;
        while(right<n){
            lastOccMap[s[right]]=right;
            int size=lastOccMap.size();
            if(size==k) ans=max(ans,right-left+1);
            else if(size>k){
                char temp=s[left];
                left=min(n-1,lastOccMap[s[left]]+1);
                lastOccMap.erase(temp);
            }
            right++;
        }
        return ans;
    }
};

int main(){

return 0;
}