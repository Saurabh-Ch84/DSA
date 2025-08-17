#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int &stone:stones)
            pq.push(stone);
        while(pq.size()>=1){
            int y=pq.top();
            pq.pop();
            if(pq.empty()) return y;
            int x=pq.top();
            pq.pop();
            int res=y-x;
            if(res) pq.push(res);
        }
        return 0;
    }
};

int main(){
    Solution s;
    // int n;
    // vector<int> stones(n);
    // for(int i=0;i<n;i++)
    //     cin>>stones[i];
    // cout<<s.lastStoneWeight(stones);
    // Test Case 1: Typical Case
    vector<int> stones1 = {2, 7, 4, 1, 8, 1};
    cout << "Output for Test Case 1: " << s.lastStoneWeight(stones1) << " (Expected: 1)" << endl;

    // Test Case 2: All Stones Are the Same
    vector<int> stones2 = {4, 4, 4, 4};
    cout << "Output for Test Case 2: " << s.lastStoneWeight(stones2) << " (Expected: 0)" << endl;

    // Test Case 3: Single Stone Edge Case
    vector<int> stones3 = {9};
    cout << "Output for Test Case 3: " << s.lastStoneWeight(stones3) << " (Expected: 9)" << endl;
return 0;
}