#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Given an array of strings, perform operations based on string length:
Even length: Convert to lowercase.
Odd length: Transform each character to its next alphabet (e.g., 'a' → 'b', 'z' → 'a').
*/

class Solution{
        public:
    string operation(string a){
        int n=a.length();
        bool isEven=(n%2==0);
        if(isEven){
            for(int i=0;i<n;i++)
                if('A'<=a[i] && a[i]<='Z') a[i]=a[i]+'a'-'A';
        }
        else{
            for(int i=0;i<n;i++)
                if(('A'<=a[i] && a[i]<='Z') || ('a'<=a[i] && a[i]<='z') ){
                    if(a[i]=='Z') a[i]='A';
                    else if(a[i]=='z') a[i]='a';
                    else a[i]+=(char)1;
                }
        }
        return a;
    }
};
int main(){
    Solution s;
    string str;
    cout<<"Enter String: ";
    cin>>str;
    cout<<"Before Operation: "<<str<<endl;
    cout<<"After Operation: "<<s.operation(str)<<endl;
return 0;
}