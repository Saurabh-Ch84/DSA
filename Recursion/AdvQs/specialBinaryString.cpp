#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string,string> hashMap;
    string recursion(string s){
        if(s.empty()) return "";
        if(hashMap.count(s)) return hashMap[s];
        int n=s.size(), sum=0, st=0;
        vector<string> specialsSubstr;
        for(int i=0;i<n;i++){
            if(s[i]=='1') sum++;
            else sum--;
            if(!sum){
                string temp=recursion(s.substr(1+st,i-st-1));
                specialsSubstr.push_back("1"+temp+"0");
                st=i+1;
            }
        }
        sort(specialsSubstr.rbegin(),specialsSubstr.rend());
        string res;
        for(string &str: specialsSubstr)
            res=res+str;
        return hashMap[s]=res;
    }
    
public:
    string makeLargestSpecial(string s) {
        return recursion(s);
    }
};

int main(){

return 0;
}