#include<bits/stdc++.h>
using namespace std;

class Solution{
    vector<int> getNSE(int m,vector<int> &arr){
        vector<int> nse(m,m);
        stack<int> st;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> getPSE(int m,vector<int> &arr){
        vector<int> pse(m,-1);
        stack<int> st;
        for(int i=0;i<m;i++){
            while(!st.empty() && arr[i]<=arr[st.top()]) st.pop();
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
    int maxRectangularArea(int m,vector<int> &height){
        vector<int> nse=getNSE(m,height);
        vector<int> pse=getPSE(m,height);
        int maxArea=0;
        for(int i=0;i<m;i++){
            int breadth=height[i], length=nse[i]-pse[i]-1;
            maxArea=max(maxArea,length*breadth);
        }
        return maxArea;
    }
        public:
    int solve(int n,int m,vector<vector<char>> &forest){
        int maxi=0;
        vector<int> height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]=='.') height[j]++;
                else height[j]=0;
            }
            maxi=max(maxi,maxRectangularArea(m,height));
        }
        return maxi;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    Solution s;
    vector<vector<char>> forest(n,vector<char>(m,'#'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>forest[i][j];
        }
    }
    cout<<s.solve(n,m,forest);
return 0;
}