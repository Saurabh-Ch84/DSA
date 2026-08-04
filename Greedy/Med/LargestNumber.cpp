#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct Comp{
        bool operator()(const int &a,const int &b){
            string A=to_string(a), B=to_string(b);
            string s1=A+B, s2=B+A;
            if(s1>s2) return true;
            return false;
        }
    };
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),Comp());
        string res;
        for(int &num: nums){
            if(!num && res.empty()) continue;
            res=res+to_string(num);
        }
        return (res.empty()? "0":res);
    }
};

int main(){

return 0;
}