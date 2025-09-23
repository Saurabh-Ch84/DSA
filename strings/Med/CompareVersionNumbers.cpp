#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int left=0,right=0;
        int n=version1.length()-count(version1.begin(),version1.end(),'.');
        int m=version2.length()-count(version2.begin(),version2.end(),'.');
        stringstream ssV1(version1),ssV2(version2);
        string tokenV1,tokenV2;

        while(left<n || right<m){
            int revNoV1=0,revNoV2=0;
            if(left<n){
                getline(ssV1,tokenV1,'.');
                left+=tokenV1.length();
                revNoV1=stoi(tokenV1);
            }
            if(right<m){
                getline(ssV2,tokenV2,'.');
                right+=tokenV2.length();
                revNoV2=stoi(tokenV2);
            }
            if(revNoV1==revNoV2) continue;
            else if(revNoV1>revNoV2) return 1;
            else return -1;
        }   
        return 0;
    }
};

int main(){
    Solution s;
    cout<<s.compareVersion("1.2","1.10");
return 0;
}