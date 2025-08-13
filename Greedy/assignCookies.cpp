#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int childPointer=0,cookiePointer=0;
        while(childPointer<g.size() && cookiePointer<s.size()){
            if(s[cookiePointer]>=g[childPointer]) childPointer++;
            cookiePointer++;
        }
        return childPointer;
    }
};

int main(){

return 0;
}