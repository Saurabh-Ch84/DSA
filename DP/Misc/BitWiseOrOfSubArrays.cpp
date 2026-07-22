#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//AI's approach
class Solution1 {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev,curr;
        unordered_set<int> result;
        for(int &num:arr){
            curr={num};
            for(const int &x:prev)
                curr.insert(x|num);
            for(const int &y:curr)
                result.insert(y);
            prev=curr;
        }
        return result.size();
    }
};

//my approach
class Solution2 {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int ptr=0,n=arr.size();
        stack<unordered_set<int>> s;
        s.push({arr[0]});
        unordered_set<int> hashSet;
        while(ptr<n){
            int num=arr[ptr++];
            hashSet.insert(num);
            unordered_set<int> prev=s.top();
            s.pop();
            unordered_set<int> curr={num};
            for(const int &n:prev){
                curr.insert(num|n);
                hashSet.insert(num|n);
            }
            s.push(curr);
        }
        return hashSet.size();
    }
};

int main(){

return 0;
}