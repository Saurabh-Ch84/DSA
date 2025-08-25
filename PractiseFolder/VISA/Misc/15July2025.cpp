#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q1.Given two strings, find a subset string of the smaller string such that both the strings can be 
made with that subset.

Q2.There are n piles of boxes of different heights which should be brought to smallest pile in the group.
one pile can be converted to another next smaller pile by removing boxes and the cost to remove each box is 1.
find the total cost to convert all n pile of boxes to smallest pile in the group.
*/

class Solution{
        public:
    string findMinSubSetStringV1(string &a,string &b){
        const string &smallerString=(a.length()<b.length())?a:b;
        unordered_set<char> setA(a.begin(),a.end());
        unordered_set<char> setB(b.begin(),b.end());
        unordered_set<char> smallerSet(smallerString.begin(),smallerString.end());
        
        unordered_set<char> requiredChars=setA;
        for(char ch:setB){
            requiredChars.insert(ch);
        }

        for(char ch:requiredChars){
            if(smallerSet.find(ch)==smallerSet.end()) return "-1";
        }

        string result(requiredChars.begin(),requiredChars.end());
        sort(result.begin(),result.end());
        return result;
    }

     // Optimization 1: More efficient union operation
    string findMinSubSetStringV2(string &a, string &b) {
        const string &smallerString = (a.length() < b.length()) ? a : b;
        unordered_set<char> smallerSet(smallerString.begin(), smallerString.end());
        // Direct union without intermediate sets
        unordered_set<char> requiredChars;
        for(char ch : a) requiredChars.insert(ch);
        for(char ch : b) requiredChars.insert(ch);
        // Check feasibility while building result
        string result;
        for(char ch : requiredChars) {
            if(smallerSet.count(ch) == 0) return "-1";
            result += ch;
        }
        sort(result.begin(), result.end());
        return result;
    }

    long long findCost(vector<int> &nums){
        int mini=INT_MAX,n=nums.size();
        long long sum=0;
        for(int &num:nums){
            sum+=num;
            mini=min(mini,num);
        }
        return (sum-1LL*n*mini);
    }
};

int main(){

    Solution s;
    string a="saurabhbhis";
    string b1="sebhaw";
    string b2="aurhbis";
    string b3="seribhaw";
    string b4="isarubhhn";

    cout<<s.findMinSubSetStringV2(a,b1)<<endl;
    cout<<s.findMinSubSetStringV2(a,b2)<<endl;
    cout<<s.findMinSubSetStringV2(a,b3)<<endl;
    cout<<s.findMinSubSetStringV2(a,b4)<<endl;

    vector<int> nums={1,14,5,8,2};
    cout<<s.findCost(nums);
return 0;
}
