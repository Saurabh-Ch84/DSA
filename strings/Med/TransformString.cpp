#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(string &s1,string &s2){
        if(s1.size()!=s2.size()) return false;
        int n=s1.size();
        unordered_map<char,int> hashMap;
        for(int i=0;i<n;i++)
            hashMap[s1[i]]++;
        for(int i=0;i<n;i++){
            hashMap[s2[i]]--;
            if(!hashMap[s2[i]])
                hashMap.erase(s2[i]);
        }
        return hashMap.empty();
    }
  public:
    int transform(string &s1, string &s2) {
        // code here
        if(!isPossible(s1,s2)) return -1;
        int i=s1.size()-1, j=s2.size()-1, count=0;
        while(i>=0 && j>=0){
            if(s1[i]==s2[j]){
                i--, j--;
            }
            else{
                i--;
                count++;
            }
        }
        return count;
    }
};


int main(){

return 0;
}