#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size(), depth=0;
        vector<int> res(n,-1);
        for(int i=0;i<n;i++){
            if(seq[i]=='(') depth++;
            if(depth%2==1) res[i]=1;
            else res[i]=0;
            if(seq[i]==')') depth--;
        }
        return res;
    }
};

int main(){

return 0;
}