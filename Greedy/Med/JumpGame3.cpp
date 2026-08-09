#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    bool DFS(int i,int n,vint &arr,vint &visited){
        if(!arr[i]) return visited[i]=1;
        if(visited[i]==-2 || visited[i]==0) return 0;
        visited[i]=-2;
        if(i-arr[i]>=0){
            bool left=DFS(i-arr[i],n,arr,visited);
            if(left) return visited[i]=1;
        }
        if(i+arr[i]<=n-1){
            bool right=DFS(i+arr[i],n,arr,visited);
            if(right) return visited[i]=1;
        }
        return visited[i]=0;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size(); //-1->unknown, 0->not possible, -2->instack, 1->possible
        vint visited(n,-1);
        return DFS(start,n,arr,visited);
    }
};

int main(){

return 0;
}