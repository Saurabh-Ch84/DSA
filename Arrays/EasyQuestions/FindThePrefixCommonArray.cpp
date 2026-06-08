#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using piint=pair<int,int>;
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size(), count=0;
        unordered_map<int,piint> hashMap;
        vint C(n,-1);
        for(int i=0;i<n;i++){
            int a=A[i], b=B[i];
            hashMap[a].first++;
            hashMap[b].second++;
            count=count+min(hashMap[a].first,hashMap[a].second);
            if(a!=b) count=count+min(hashMap[b].first,hashMap[b].second);
            C[i]=count;
        }
        return C;
    }
};

int main(){

return 0;
}