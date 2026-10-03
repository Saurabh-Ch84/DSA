#include<bits/stdc++.h>
using namespace std;

class Solution {
    int DFS(int u,vector<pair<int,int>> &A,vector<bool> &visited){
        if(visited[u]) return 0;
        visited[u]=1;
        int v=A[u].second;
        return 1+DFS(v,A,visited);
    }
    int cycleDecompostion(vector<pair<int,int>> &A,int n){
        vector<bool> visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            int j=A[i].second;
            if(visited[i] || i==j) continue;
            int swaps=DFS(i,A,visited)-1;
            count+=swaps;
        }
        return count;
    }
  public:
    int minSwaps(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<pair<int,int>> A;
        for(int i=0;i<n;i++){
            A.push_back({arr[i],i});
        }
        sort(A.begin(),A.end());
        int mini=cycleDecompostion(A,n);
        return mini;
    }
};

int main(){

return 0;
}