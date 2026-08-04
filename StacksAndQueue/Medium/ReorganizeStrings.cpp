#include<bits/stdc++.h>
using namespace std;

class Solution {
    using pic=pair<int,char>;
    using vint=vector<int>;
public:
    string reorganizeString(string s) {
        int n=s.size();
        vint alphabets(26,0);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            alphabets[idx]++;
        }
        priority_queue<pic> pq;
        for(int i=0;i<26;i++){
            if(alphabets[i])
                pq.push({alphabets[i],'a'+i});
        }
        string res;
        pic buffer={0,'#'};
        while(res.size()<n){
            if(!pq.empty()){
                pic entry=pq.top(); pq.pop();
                int freq=entry.first;
                res.push_back(entry.second);
                if(buffer.first) {
                    pq.push(buffer);
                    buffer.first=0;
                }
                if(freq>1) buffer={freq-1,entry.second};
            }
            else{
                if(buffer.first!=1 || res.back()==buffer.second) return "";
                res.push_back(buffer.second);
                buffer.first=0;
            }
        }
        return res;
    }
};

int main(){

return 0;
}