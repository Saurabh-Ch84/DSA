#include<iostream>
#include<vector>
using namespace std;

class Solution2 {
    using vint=vector<int>;
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vint alphabetsLastIdx(26,-1);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            alphabetsLastIdx[idx]=i;
        }
        vint res;
        int left=0;
        while(left<n){
            int right=left;
            for(int i=left;i<=right;i++){
                int idx=s[i]-'a';
                int lastIdx=alphabetsLastIdx[idx];
                right=max(right,lastIdx);
            }
            int sz=right-left+1;
            res.push_back(sz);
            left=right+1;
        }
        return res;
    }
};

class Solution1 {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        vector<int> arr(26,0);
        for(int i=0;i<n;i++)
            arr[s[i]-'a']=i;

        vector<int> res;
        int left=0,right=0;
        for(int i=0;i<n;i++){
            right=max(right,arr[s[i]-'a']);
            if(i==right){
                res.push_back(right-left+1);
                left=i+1;
            }
        }
        return res;
    }
};

int main(){

return 0;
}