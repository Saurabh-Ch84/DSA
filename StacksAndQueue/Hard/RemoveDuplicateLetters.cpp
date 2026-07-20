#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
public:
    string removeDuplicateLetters(string s) {
        int n=s.length(), count=0;
        vint lastOccurence(26,-1);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(lastOccurence[idx]==-1) count++;
            lastOccurence[idx]=i;
        }
        string res, temp;
        unordered_set<char> hashSet;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            while(!temp.empty() && !hashSet.count(s[i]) && temp.back()>=s[i] && lastOccurence[temp.back()-'a']>i){
                hashSet.erase(temp.back());
                temp.pop_back();
            }
            if(!hashSet.count(s[i])){
                temp.push_back(s[i]);
                hashSet.insert(s[i]);
            }
            if(temp.size()==count)
                res=(res.empty()? temp: min(res,temp));
        }
        return res;
    }
};

int main(){

return 0;
}