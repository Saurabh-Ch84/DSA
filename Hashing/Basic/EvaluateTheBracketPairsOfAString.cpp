#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,int> hashMap;
        int n=knowledge.size();
        for(int i=0;i<n;i++)
            hashMap[knowledge[i][0]]=i;

        string res;
        int i=0, m=s.size();
        while(i<m){
            if(s[i]=='('){
                string key;
                i++;
                while(i<m && s[i]!=')'){
                    key.push_back(s[i]);
                    i++;
                }
                if(hashMap.count(key)){
                    int j=hashMap[key];
                    res+=knowledge[j][1];
                }
                else res.push_back('?');
                i++;
            }
            else{
                while(i<m && s[i]!='('){
                    res.push_back(s[i]);
                    i++;
                }
            }
        }
        return res;
    }
};

int main(){

return 0;
}