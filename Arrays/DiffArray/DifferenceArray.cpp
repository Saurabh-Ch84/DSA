#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
 Question 1: Given ‘n’ Jars filled with ‘m’ number of Jellybeans.‘T’ represents the number 
 of operations performed on these jars. Given a range [a-b] and number of jelly beans to be filled in 
 the jars lying in the range [a-b], find the number of jelly beans in each jar after these ‘T’ operations.
*/

class Solution{
        public:
    void findJellyBeansInJars(int n, int m, int T, vector<vector<int>> &ranges) {
        vector<int> diffArr(n+1, 0);
        for (vector<int> &range : ranges) {
            int a = range[0] - 1, b = range[1] - 1;
            int val = range[2];
            diffArr[a] += val;
            diffArr[b+1] -= val;
        }
        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += diffArr[i];
            cout << m + curr << " ";
        }
    }

};


int main(){
    Solution s;
    vector<vector<int>> nums1={{1,2,4},{1,3,1}};
    s.findJellyBeansInJars(6,5,nums1.size(),nums1);
return 0;
}