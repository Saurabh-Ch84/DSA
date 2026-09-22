#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct Comp{
        bool operator()(const pair<int,int> &a,const pair<int,int> &b){
            int aL=a.first, aR=a.second;
            int bL=b.first, bR=b.second;
            if(aR==bR){
                if(aL<bL) return 1;
                return 0;
            }
            if(aR<bR) return 1;
            return 0;
        }
    };
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<pair<int,int>> startAndEnd(26,{-1,-1});
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(startAndEnd[idx].first==-1)
                startAndEnd[idx].first=i;
            startAndEnd[idx].second=i;
        }

        vector<pair<int,int>> intervals;
        for(int idx=0;idx<26;idx++){
            if(startAndEnd[idx].first==-1) continue;
            int i=startAndEnd[idx].first, j=startAndEnd[idx].second;
            bool isValid=1;
            for(int k=i;k<=j;k++){
                int idx_=s[k]-'a';
                if(startAndEnd[idx_].first==-1) continue;
                if(startAndEnd[idx_].first<i){
                    isValid=0;
                    break;
                }
                j=max(j,startAndEnd[idx_].second);
            }
            if(isValid) intervals.push_back({i,j});
        }

        sort(intervals.begin(),intervals.end(),Comp());
        vector<string> res;
        int m=intervals.size(), prevEnd=-1;
        for(int i=0;i<m;i++){
            int start=intervals[i].first, end=intervals[i].second;
            if(prevEnd==-1 || start>prevEnd){
                res.push_back(s.substr(start,end-start+1));
                prevEnd=end;
            }   
        }
        return res;
    }
};

int main(){

return 0;
}