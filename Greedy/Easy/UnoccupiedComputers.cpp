#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(int n, string s) {
        // code here
        int m=s.size(), count=0;
        vector<int> customers(26,0);
        for(int i=0;i<m;i++){
            int idx=s[i]-'A';
            if(customers[idx]==1) n++;
            else if(!customers[idx] && n) n--;
            else{
                if(!customers[idx]) count++;
                customers[idx]=-1;
                continue;
            }
            customers[idx]=1^customers[idx];
        }
        return count;
    }
};


int main(){

return 0;
}