#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    time limit per test1 second
memory limit per test256 megabytes
"You must lift the dam. With a lever. I will give it to you.
You must block the canal. With a rock. I will not give the rock to you."

Danik urgently needs rock and lever! Obviously, the easiest way to get these things is to ask Hermit Lizard for them.

Hermit Lizard agreed to give Danik the lever. But to get a stone, Danik needs to solve the following task.

You are given a positive integer n, and an array a of positive integers. 
The task is to calculate the number of such pairs (i,j) that i<j and ai&aj ≥ ai⊕aj, 
 where & denotes the bitwise AND operation, and ⊕ denotes the bitwise XOR operation.
Danik has solved this task. But can you solve it?

Input
Each test contains multiple test cases.

The first line contains one positive integer t
 (1≤t≤10) denoting the number of test cases. Description of the test cases follows.

The first line of each test case contains one positive integer n
 (1≤n≤1e5) — length of the array.

The second line contains n
 positive integers ai
 (1≤ai≤1e9) — elements of the array.

It is guaranteed that the sum of n
 over all test cases does not exceed 1e5.

Output
For every test case print one non-negative integer — the answer to the problem.

Example
Input
5
5
1 4 3 7 10
3
1 1 1
4
6 2 5 3
2
2 4
1
1
Output
1
3
2
0
0
*/

class Solution{
    vector<int> groupByHighestSetBit(vector<int>& nums){
        vector<int> ans(32,0);
        for(int &num:nums){
            for(int i=31;i>=0;i--){
                if(num & (1<<i)){
                    ans[i]++;
                    break;
                }
            }
        }
        return ans;
    }
        public:
    long long countResPairs(vector<int>& nums){
        vector<int> ans=groupByHighestSetBit(nums);
        long long sum=0;
        for(int k=0;k<32;k++)
            sum+=(1LL*ans[k]*(ans[k]-1))/2;
        return sum;
    }
};

int main(){
    Solution s;
    int q;
    cin>>q;
    while(q){
        int sz;
        cin>>sz;
        vector<int> v(sz);
        for(int i=0;i<sz;i++)
            cin>>v[i];
        cout<<s.countResPairs(v)<<endl;
        q--;
    }
return 0;
}