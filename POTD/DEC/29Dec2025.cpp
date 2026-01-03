#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>

using namespace std;
using un_mapss = unordered_map<string,string>;
using un_mapsb = unordered_map<string,bool>;
using vs = vector<string> ;
using str= string;

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n=a.size(), m=b.size();
        if(n>m) return kthElement(b,a,k);
        int low=max(0,k-m), high=min(k,n);
        while(low<=high){
            int cut1=low+(high-low)/2;
            int cut2=k-cut1;
            
            int left1=(cut1>0)? a[cut1-1] : INT_MIN;
            int left2=(cut2>0)? b[cut2-1] : INT_MIN;
            
            int right1=(cut1<n)? a[cut1] : INT_MAX;
            int right2=(cut2<m)? b[cut2] : INT_MAX;
            
            if(left1<=right2 && left2<=right1){
                return max(left1,left2);
            }
            else if(left1>right2){
                high=cut1-1;    
            }
            else{
                low=cut1+1;
            }
        }
        return -1;
    }
};

// Optimal
class Solution {
    bool nextRow(int i,int n,str &bottom,un_mapss &hashMap,str &temp,un_mapsb &dp){
        if(temp.length()==n-1){
            return recursion(temp,hashMap,dp);
        }
        if(i>n-2) return false;
        string window=bottom.substr(i,2);
        if(!hashMap.count(window)) return false;
        for(char letter: hashMap[window]){
            temp.push_back(letter);
            if(nextRow(i+1,n,bottom,hashMap,temp,dp))
                return true;
            temp.pop_back();
        }
        return false;
    }
    bool recursion(str &bottom,un_mapss &hashMap,un_mapsb &dp){
        int n=bottom.length();
        if(n==1) return true;
        if(dp.count(bottom)) return dp[bottom];
        string temp;
        bool nextAns=nextRow(0,n,bottom,hashMap,temp,dp);
        return dp[bottom]=nextAns;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,string> hashMap;
        unordered_map<string,bool> dp;
        for(string &pattern: allowed)
            hashMap[pattern.substr(0,2)].push_back(pattern[2]);
        
        return recursion(bottom,hashMap,dp);
    }
};

// Better
class Solution {
    void nextPossibleRows(int i,int n,string &bottom,un_mapss &hashMap,vs &options,string &temp){
        if(temp.length()==n-1){
            options.push_back(temp);
            return ;
        }
        if(i>n-2) return ;
        string window=bottom.substr(i,2);
        if(!hashMap.count(window)) return ;
        string choices=hashMap[window];
        for(char letter: choices){
            temp.push_back(letter);
            nextPossibleRows(i+1,n,bottom,hashMap,options,temp);
            temp.pop_back();
        }
    }
    bool recursion(string &bottom,un_mapss &hashMap,un_mapsb &dp){
        int n=bottom.length();
        if(n==1) return true;
        if(dp.count(bottom)) return dp[bottom];
        string temp;
        vs options;
        nextPossibleRows(0,n,bottom,hashMap,options,temp);
        for(string &newBottom: options){
            bool nextAns=recursion(newBottom,hashMap,dp);
            if(nextAns) return dp[bottom]=true;
        }
        return dp[bottom]=false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,string> hashMap;
        unordered_map<string,bool> dp;
        for(string &pattern: allowed)
            hashMap[pattern.substr(0,2)].push_back(pattern[2]);
        
        return recursion(bottom,hashMap,dp);
    }
};

int main(){

return 0;
}