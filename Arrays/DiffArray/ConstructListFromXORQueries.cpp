#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
  public:
    vint constructList(vvint &queries) {
        // code here
        vint res={0}, diffArr(1e5+1,0);
        for(vint &query: queries){
            if(query[0]){
                diffArr[0]^=query[1];
                diffArr[res.size()]^=query[1];
            }
            else res.push_back(query[1]);
        }
        res[0]^=diffArr[0];
        for(int i=1;i<res.size();i++){
            diffArr[i]=diffArr[i]^diffArr[i-1];
            res[i]=res[i]^diffArr[i];
        }
        sort(res.begin(),res.end());
        return res;
    }
};




int main(){

return 0;
}