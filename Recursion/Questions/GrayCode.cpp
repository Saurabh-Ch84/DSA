#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> recursion(int n){
        if(n==0) return {""};

        vector<string> prev=recursion(n-1);
        vector<string> curr;
        int m=prev.size();
        
        for(int i=0;i<m;i++)
            curr.push_back("0"+prev[i]);
        
        for(int i=m-1;i>=0;i--)
            curr.push_back("1"+prev[i]);
        
        return curr;
    }

    int binaryToInt(string &binary){
        int integer=0,n=binary.size();
        for(int i=n-1;i>=0;i--){
            if(binary[i]=='1') integer=integer|(1<<(n-1-i));
        }
        return integer;
    }
public:
    vector<int> grayCode1(int n) {
        vector<string> grayCode=recursion(n);
        vector<int> result;
        for(string &binary:grayCode){
            int num=binaryToInt(binary);
            result.push_back(num);
        }
        return result;
    }

    vector<int> grayCode2(int n) {
        vector<int> result;
        int m = 1 << n; 
        for (int i = 0; i < m; i++)
            result.push_back(i ^ (i >> 1));
    
        return result;
        
    }
};

void print(vector<int> v){
    for(int &val:v) cout<<val<<" ";
    cout<<"\n";
}


int main(){
    Solution s;
    print(s.grayCode2(10));
    print(s.grayCode1(5));
return 0;
}