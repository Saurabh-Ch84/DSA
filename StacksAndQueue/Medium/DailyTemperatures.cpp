#include<iostream>
#include<stack>
#include<vector>
using namespace std;

using pii = pair<int,int> ;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pii> monos;
        int n=temperatures.size();
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--){
            int temp=temperatures[i];
            while(!monos.empty() && monos.top().first<=temp)
                monos.pop();
            int days=(monos.empty())? 0:monos.top().second-i;
            monos.push({temp,i});
            res[i]=days;
        }
        return res;
    }
};

int main(){

return 0;
}