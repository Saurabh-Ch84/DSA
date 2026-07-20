#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    using vint=vector<int>;
    void recursion(int i,int n,string &res,string &temp,string &s,unordered_set<char> &hashSet){
        if(i==n){
            if(hashSet.empty())
                res=(res.empty()? temp: min(res,temp));
            return ;
        }
        //notTake
        recursion(i+1,n,res,temp,s,hashSet);
        if(hashSet.count(s[i])){
            //take 
            hashSet.erase(s[i]);
            temp.push_back(s[i]);
            recursion(i+1,n,res,temp,s,hashSet);
            temp.pop_back();
            hashSet.insert(s[i]);
        }
    }
public:
    string smallestSubsequence(string s) {
        string res, temp;
        int n=s.length();
        unordered_set<char> hashSet;
        for(int i=0;i<n;i++)
            hashSet.insert(s[i]);
        recursion(0,n,res,temp,s,hashSet);
        return res;
    }
};
class Solution {
    using vint=vector<int>;
public:
    string smallestSubsequence(string s) {
        int n=s.length(), count=0;
        vint lastIdx(26,-1);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(lastIdx[idx]==-1) count++;
            lastIdx[idx]=i;
        }
        string res, temp;
        unordered_set<char> chSet;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            while(!temp.empty() && !chSet.count(s[i]) && temp.back()>s[i] && lastIdx[temp.back()-'a']>i){
                chSet.erase(temp.back());
                temp.pop_back();
            }
            if(!chSet.count(s[i])){
                chSet.insert(s[i]);
                temp.push_back(s[i]);
            }
            if(temp.size()==count){
                // res=(res.empty()? temp: min(res,temp));
                res=temp;
                break;
            }
        }
        return res;
    }
};

int main(){

return 0;
}