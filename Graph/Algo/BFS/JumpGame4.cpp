#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;

    int BFS(int src,int n,vint &arr,unordered_map<int,vint> &hashMap){
        queue<int> q;
        vint visited(n,0);
        q.push(src);
        visited[src]=1;
        int moves=0, dest=n-1;

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int u=q.front(); q.pop();
                if(u==dest) return moves;
                int uVal=arr[u];
                for(int &v: hashMap[uVal]){
                    if(visited[v] || v==u) continue;
                    visited[v]=1;
                    q.push(v);
                }
                hashMap.erase(uVal); // optimization.
                if(u!=n-1 && !visited[u+1]){
                    visited[u+1]=1;
                    q.push(u+1);
                }
                if(u && !visited[u-1]){
                    visited[u-1]=1;
                    q.push(u-1);
                }
            }
            moves++;
        }
        return -1;
    }
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vint> hashMap;
        for(int i=0;i<n;i++){
            if(i && i!=n-1 && arr[i-1]==arr[i] && arr[i+1]==arr[i])
                continue;
            hashMap[arr[i]].push_back(i);
        }
        return BFS(0,n,arr,hashMap);
    }
};

int main(){

return 0;
}