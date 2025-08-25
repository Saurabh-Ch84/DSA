#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int> diffArr(n+1,0);
        for(vector<int> &shift:shifts){
            int left=shift[0],right=shift[1];
            int shiftDir=(shift[2]==1)?1:-1;
            diffArr[left]+=shiftDir;
            diffArr[right+1]-=shiftDir;
        }
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=diffArr[i];
            s[i] = (s[i] - 'a' + curr % 26 + 26) % 26 + 'a';
        }
        return s;    
    }
};

int main(){
    Solution s;
    vector<vector<int>> shifts={{1,2,0},{0,2,1},{2,4,1}};
    cout<<s.shiftingLetters("saurabh",shifts);
return 0;
}