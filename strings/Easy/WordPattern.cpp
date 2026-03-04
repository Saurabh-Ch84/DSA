#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int i=0, n=pattern.length();
        if(count(s.begin(),s.end(),' ')+1!=n) return false;

        unordered_map<char,string> hashMap;
        unordered_set<string> hashSet;
        stringstream ss(s);
        string token;

        while(i<n && getline(ss,token,' ')){
            if(hashMap.count(pattern[i]) && hashMap[pattern[i]]!=token)
                return false;
            if(!hashMap.count(pattern[i]) && hashSet.count(token))
                return false;
            if(!hashMap.count(pattern[i]))
                hashMap[pattern[i]]=token;
            if(!hashSet.count(token))
                hashSet.insert(token);  
            i++;
        }
        return true;
    }
};

int main(){

return 0;
}