#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        vector<vector<int>> arr(26);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            arr[idx].push_back(i);
        }

        int totalCount=0;
        for(int i=0;i<26;i++){
            if(arr[i].size()<2) continue;
            int left=arr[i][0],right=arr[i].back();
            unordered_set<char> hashSet;
            for(int j=left+1;j<right;j++)
                hashSet.insert(s[j]);
            int count=hashSet.size();
            totalCount+=count;
        }

        return totalCount;
    }
};

int main(){

return 0;
}