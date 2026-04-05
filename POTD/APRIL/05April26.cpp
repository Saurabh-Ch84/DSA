#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontal=0, vertical=0;
        for(const char &move: moves){
            if(move=='L') horizontal--;
            else if(move=='R') horizontal++;
            else if(move=='D') vertical--;
            else vertical++;
        }
        return (!horizontal && !vertical);
    }
};

class Solution {
    using vint=vector<int>;
    using  memo_t=unordered_map<int,unordered_map<int,int>>;
    int recursion(int i,int n,vint &arr,int target,memo_t &hashMap){
        if(i==n) return (!target);
        if(hashMap.count(i) && hashMap[i].count(target)) 
            return hashMap[i][target];
        int takeNeg=recursion(i+1,n,arr,target+arr[i],hashMap);
        int takePos=recursion(i+1,n,arr,target-arr[i],hashMap);
        return hashMap[i][target]=takeNeg+takePos;
    }
  public:
    int totalWays(vector<int>& arr, int target) {
        //  code here
        int n=arr.size();
        memo_t hashMap;
        return recursion(0,n,arr,target,hashMap);
    }
};

int main(){

return 0;
}