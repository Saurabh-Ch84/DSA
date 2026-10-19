#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> PSE(vector<int> &arr,int n){
        vector<int> pse(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int> NSE(vector<int> &arr,int n){
        vector<int> nse(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n=arr.size();
        vector<int> windowSizesMax(n+1,0);
        vector<int> pse=PSE(arr,n), nse=NSE(arr,n);
        for(int i=0;i<n;i++){
            int windowSize=nse[i]-pse[i]-1;
            windowSizesMax[windowSize]=max(windowSizesMax[windowSize],arr[i]);
        }
        for(int i=n-1;i>=0;i--){
            windowSizesMax[i]=max(windowSizesMax[i],windowSizesMax[i+1]);
        }
        vector<int> res(n);
        for(int i=1;i<=n;i++){
            res[i-1]=windowSizesMax[i];
        }
        return res;
    }
};

int main(){

return 0;
}