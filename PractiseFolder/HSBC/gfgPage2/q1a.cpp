#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    Q1. 1367(be it any number) write a code to convert it into words.
*/

class Solution{
    unordered_map<char,string> aMap;
    unordered_map<int,string> bMap;
        public: 
    Solution(){
        aMap={
            {'1',"One"},{'2',"Two"},{'3',"Three"},{'4',"Four"},
            {'5',"Five"},{'6',"Six"},{'7',"Seven"},{'8',"Eight"},{'9',"Nine"},
        };
    
        bMap={{1,"One"},{2,"Ten"},{3,"Hundred"},{4,"Thousand"},{5,"Ten Thousand"},{6,"Lakh"},
                {7,"Ten Lakh"},{8,"Crore"},{9,"Ten Crore"}};
    }
    string q(int number){
        string str=to_string(number);
        int n=str.length();
        string res;
        for(int i=0;i<n;i++){
            int place=n-i;
            if(str[i]=='0') continue;
            if(str[i]>'1')
                res+=aMap[str[i]]+" "+bMap[place]+"s ";
            else
                res+=aMap[str[i]]+" "+bMap[place]+" ";
        }
        return res;
    }
};

int main(){
    Solution s;
    cout<<s.q(1367);
return 0;
}