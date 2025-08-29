#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Given an empty array and a series of queries (+x to add, -x to remove),count unique
triplets (a, b, c) such that a - b = b - c = 'diff'. Return results after each query.
*/

class Solution1 {
    set<int> hashSet;
        public:
    Solution1(){
        hashSet.clear();
    }
    int getCount(){
        int sz=hashSet.size();
        if(hashSet.size()<3) return 0;
        int countTriplets=0;
        vector<int> hashArray(hashSet.begin(),hashSet.end());
        for(int i=0;i<sz;i++){
            int leftVal=hashArray[i];
            for(int j=sz-1;j>i;j--){
                int rightVal=hashArray[j];
                if((leftVal+rightVal)%2==0){
                    int mid=(leftVal+rightVal)/2;
                    countTriplets+=hashSet.count(mid);
                }
            }
        }
        return countTriplets;
    }
    void add(int num){
        hashSet.insert(num);
    }

    void remove(int num){
        hashSet.erase(num);
    }
};

void print(vector<int>& ans) {
    for (int& val : ans)
        cout << val << " ";
    cout << endl;
}

int main(){
    Solution1 s;
    vector<int> queries = {1, 3, 5, 7, -3, 9};
    vector<int> res;
    for(int i=0;i<queries.size();i++){
        bool isAdd=(queries[i]>0);
        if(isAdd) s.add(queries[i]);
        else s.remove(-queries[i]);
        int ans=s.getCount();
        res.push_back(ans);
    }
    print(res);
    return 0;
}