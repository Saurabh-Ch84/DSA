#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
    void getNSE(vector<int> &nse, vector<int> &arr, int n){
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
                    st.pop();
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }
    }
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n=arr.size(), count=0;
        vector<int> nse(n,n);
        getNSE(nse,arr,n);
        
        for(int i=0;i<n;i++)
            count+=max(0,nse[i]-i);
        return count;
    }
};

int main(){

return 0;
}