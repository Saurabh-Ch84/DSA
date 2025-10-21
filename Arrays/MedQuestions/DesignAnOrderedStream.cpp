#include<iostream>
#include<vector>
using namespace std;

class OrderedStream {
    int ptr,n;
    vector<string> dp;
public:
    OrderedStream(int n) {
        this->n=n;
        dp.resize(n+1);
        ptr=1;
    }
    
    vector<string> insert(int idKey, string value) {
        dp[idKey]=value;
        if(dp[ptr].empty()) return {};

        vector<string> ans;
        for(int i=ptr;i<=n;i++){
            if(dp[i].empty()) break;
            ans.push_back(dp[i]);
            ptr=i+1;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

int main(){

return 0;
}