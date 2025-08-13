#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    void print(vector<int> &v){
        for(int &val:v)
            cout<<val<<" ";
        cout<<endl;
    }
        public:
    vector<int> computeLPS(string &str){
        int n=str.length();
        vector<int> lps(n,0);
        int len=0,i=1;
        while(i<n){
            if(str[i]==str[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len) len=lps[len-1];
                else i++;
            }
        }
        print(lps);
        return lps;
    }
    bool isMatching(string &str,string &target){
        int n=str.length(),m=target.length();
        vector<int> lps=computeLPS(target);
        int i=0,j=0;
        while(i<n){
            if(str[i]==target[j]){
                i++;
                j++;
                if(j==m) return true;
            }
            else{
                if(j>0) j=lps[j-1];
                else i++;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    string str,target;
    cout<<"Enter String: ";
    cin>>str;
    cout<<"Enter Target: ";
    cin>>target;
    cout<<s.isMatching(str,target)<<endl;
return 0;
}