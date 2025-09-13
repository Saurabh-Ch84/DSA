#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    Boneca Ambalabu gives you a sequence of n
 integers a1,a2,…,an
.

Output the maximum value of (ak⊕a1)+(ak⊕a2)+…+(ak⊕an)
 among all 1≤k≤n
. Note that ⊕
 denotes the bitwise XOR operation.

Input
The first line contains an integer t
 (1≤t≤104
) – the number of independent test cases.

The first line of each test case contains an integer n
 (1≤n≤2⋅105
) – the length of the array.

The second line of each test case contains n
 integers a1,a2,…,an
 (0≤ai<230
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the maximum value on a new line.
*/

class Solution{
    vector<int> precomputeBitsSetCountArr(vector<int> &nums){
        vector<int> bitsCount(30,0);
        for(int &num:nums){
            for(int i=0;i<30;i++){
                if(num & (1<<i)) bitsCount[i]++;
            }
        }
        return bitsCount;
    }
        public:
    long long maximiseXORSum(vector<int> &nums){
        int n=nums.size();
        vector<int> bitsCount=precomputeBitsSetCountArr(nums);
        long long ans=0;
        for(int &num:nums){
            long long sum=0;
            for(int i=0;i<30;i++){
                if(num & (1<<i))
                    sum+=1LL*(n-bitsCount[i])*(1<<i);
                else
                    sum+=1LL*bitsCount[i]*(1<<i);
            }
            ans=max(ans,sum);
        }
        return ans;
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
        for(int i=0;i<sz;i++) cin>>v[i];
        cout<<s.maximiseXORSum(v)<<"\n";
        q--;
    }
return 0;
}