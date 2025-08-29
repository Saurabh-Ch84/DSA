#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*

We were given string of n, where str[i] denotes the binary number . For example if str[i]="3415" then our 
deduced binary number will be : 11101 (set bits on position 1, 3, 4 and 5 from end, positions not given can 
be assumed to be zero). Problem was to sort these strings on increasing order of their binary numbers.

*/

class Solution{
    static int binaryVal(string s){
        int val=0;
        for(char digit:s){
            int pos=digit-'0';
            val=val|(1<<(pos-1));
        }
        return val;
    }
    static bool comp(const string &a,const string &b){
        return binaryVal(a)<binaryVal(b);
    }
        public:
    void customSort(vector<string> &nums){
        sort(nums.begin(),nums.end(),comp);
    }

    vector<string> parseInput(const string &input){
        vector<string> result;
        stringstream ss(input);
        string token;
        while(getline(ss,token,','))
            result.push_back(token);
        return result;
    }
};

void print(vector<string> &nums){
    for(const string &num:nums)
        cout<<num<<" ";
    cout<<endl;
}

int main(){
    Solution s;
    string str="3415,12,89,13,3";
    vector<string> nums=s.parseInput(str);
    print(nums);
    s.customSort(nums);
    print(nums);
    str.clear();
    for(const string &num:nums) str+=num+',';
    str.pop_back();
return 0;
}