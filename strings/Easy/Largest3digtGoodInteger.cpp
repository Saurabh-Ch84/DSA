#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //optimal but overkill
    string largestGoodInteger1(string num) {
        int n=num.length();
        int left=0,right=0;
        unordered_map<char,int> hashMap;
        string maxGoodInt="";
        while(right<n){
            hashMap[num[right]]++;
            while(hashMap.size()>1){
                hashMap[num[left]]--;
                if(hashMap[num[left]]==0)
                    hashMap.erase(num[left]);
                left++;
            }
            pair<char,int> p=*hashMap.begin();
            if(p.second==3){
                if(maxGoodInt.empty()) maxGoodInt=num.substr(left,3);
                else maxGoodInt=max(maxGoodInt,num.substr(left,3));
            }
            right++;
        }
        return maxGoodInt;
    }
    //optimal
    string largestGoodInteger2(string num) {
        string maxGoodInt="";
        int n=num.length();
        for(int i=0;i+2<n;i++){
            char digit=num[i];
            if(num[i+1]==digit && num[i+2]==digit)
                maxGoodInt=max(maxGoodInt,num.substr(i,3));
        }
        return maxGoodInt;
    }
};

int main(){

return 0;
}