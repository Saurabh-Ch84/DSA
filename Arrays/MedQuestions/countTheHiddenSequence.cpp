#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool recursion(vector<int>& differences,int num,int i,int n,int lower,int upper){
        if(i==n) return true;
        int num_=num+differences[i];
        if(!isValid(num_,lower,upper)) return false;
        return recursion(differences,num_,i+1,n,lower,upper);
    }

    bool isValid(int num,int lower,int upper){
        return (lower<=num && num<=upper);
    }
    
public:
    int numberOfArraysBrute(vector<int>& differences, int lower, int upper) {
        int count=0,n=differences.size();
        for(int num=lower;num<=upper;num++){
            if(recursion(differences,num,0,n,lower,upper)) count++;
        }
        return count;
    }

    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr=0;
        int maxVal=0,minVal=0;
        for(int &diff:differences){
            curr=curr+diff;
            minVal=min(minVal,curr);
            maxVal=max(maxVal,curr);
            if((upper-maxVal)-(lower-minVal)+1<=0) return 0;
        }
        return (upper-maxVal)-(lower-minVal)+1;
    }
};

int main(){
    Solution s;
    vector<int> differences={1,2,-1,0};
    int lower=2,upper=6;
    cout<<s.numberOfArrays(differences,lower,upper);
return 0;
}