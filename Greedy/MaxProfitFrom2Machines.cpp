#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vpiint=vector<pair<int,int>>;
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        // code here
        int n=a.size();
        vpiint arr;
        for(int i=0;i<n;i++) 
            arr.push_back({abs(a[i]-b[i]),i});
        
        sort(arr.rbegin(),arr.rend());
        int i=0, j=0, profit=0;
        for(int k=0;k<n;k++){
            int idx=arr[k].second;
            if(a[idx]>=b[idx]){
                if(i==x){
                    profit+=b[idx];
                    j++;
                }
                else{
                    profit+=a[idx];
                    i++;
                }
            }
            else{
                if(j==y){
                    profit+=a[idx];
                    i++;
                }
                else{
                    profit+=b[idx];
                    j++;
                }
            }
        }
        return profit;
    }
};

int main(){

return 0;
}