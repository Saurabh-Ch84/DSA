#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size(), left=0, right=0, ones=0;
        int mini=n+1, i=-1;
        string_view sv(s);
        while(right<n){
            ones=ones+(s[right]-'0');
            while(ones>=k && left<=
                  right){
                if(ones==k){
                    int len=right-left+1;
                    if(len<mini || (len==mini && sv.substr(left,len)<sv.substr(i,mini))){
                        i=left;
                        mini=len;
                    }
                }
                ones=ones-(s[left]-'0');
                left++;
            }
            right++;
        }
        return (i==-1? "":s.substr(i,mini));
    }
};


int main(){

return 0;
}