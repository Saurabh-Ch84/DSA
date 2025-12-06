#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

using vi = vector<int> ;
class Solution {
    struct Comp{
        bool operator()(const vi &a,const vi &b) const{
            int A=a[1]-a[0]+1;
            int B=b[1]-b[0]+1;
            if(A!=B) return A>B;
            return a[0]<b[0];
        }
    };
    int findAns(int m,int &ptr,int query,vector<vi> &intervals,priority_queue<vi,vector<vi>,Comp> &pq){
        while(ptr<m && intervals[ptr][0]<=query){
            int left=intervals[ptr][0];
            int right=intervals[ptr][1];
            if(right>=query)
                pq.push(intervals[ptr]);
            ptr++;
        }
        while(!pq.empty() && pq.top()[1]<query){
            pq.pop();
        }
        if(!pq.empty()){
            vi range=pq.top();
            int size=range[1]-range[0]+1;
            return size;
        }
        return -1;
    }
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n=queries.size();
        unordered_map<int,vector<int>> hashMap;
        for(int i=0;i<n;i++) hashMap[queries[i]].push_back(i);
        
        sort(queries.begin(),queries.end());
        sort(intervals.begin(),intervals.end());

        priority_queue<vi,vector<vi>,Comp> pq;
        vector<int> res(n,-1);
        int ptr=0,m=intervals.size();
        for(int &query: queries){
            int ans=findAns(m,ptr,query,intervals,pq);
            for(int idx: hashMap[query])
                res[idx]=ans;
        }
        return res;
    }
};

int main(){

return 0;
}