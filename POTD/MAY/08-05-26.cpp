#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
    using vbool=vector<bool>;
    vbool Sieve(int n){
        vbool prime(n+1,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i<=n;i++){
            if(!prime[i]) continue;
            for(long j=1L*i*i;j<=n;j+=i)
                prime[j]=false;
        }
        return prime;
    }

    int BFS(int s,int d,int n,vvint &adjList){
        int cost=0;
        queue<int> q;
        vbool visited(n,0);
        q.push(s);
        visited[s]=1;

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int u=q.front(); q.pop();
                if(u==d) return cost;
                for(int &v: adjList[u]){
                    if(!visited[v]){
                        visited[v]=1;
                        q.push(v);
                    }
                }
            }
            cost++;
        }
        return -1;
    }
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size(), maxi=0;
        unordered_map<int,vint> hashMap;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            hashMap[nums[i]].push_back(i);
        }
        vbool prime=Sieve(maxi);
        unordered_set<int> primeSet;
        for(int i=0;i<=maxi;i++){
            if(prime[i] && hashMap[i].size()) 
                primeSet.insert(i);
        }

        vvint adjList(n);
        for(int i=0;i<n;i++){
            if(i) adjList[i].push_back(i-1);
            if(i!=n-1) adjList[i].push_back(i+1);
            if(nums[i]==1) continue;
            for(const int &p: primeSet){
                if(nums[i]%p==0){
                    for(int &index: hashMap[p]){
                        if(index==i || index==i-1 || index==i+1) 
                            continue;
                        adjList[index].push_back(i);
                    }
                }
            }
        }

        return BFS(0,n-1,n,adjList);
    }
};


class Solution {
public:
    vector<bool> isPrime;
    
    void buildSieve(int maxEl) {
        //fill isPrime
        isPrime.resize(maxEl+1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int num = 2; num*num <= maxEl; num++) {
            if(isPrime[num]) {

                for(int multiple = num*num; multiple <= maxEl; multiple += num) {
                    isPrime[multiple] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp; //element -> indices
        int maxEl = 0;
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            maxEl = max(maxEl, nums[i]);
        }

        //build isPrime vector using Sieve
        buildSieve(maxEl); //O(maxEL * loglog(maxEl));

        queue<int> que;
        vector<bool> visited(n, false);
        que.push(0);
        visited[0] = true;

        unordered_set<int> seen;

        int steps = 0;
        //We visit each node only once - O(n)
        //O(n + maxEL * loglog(maxEl));
        while(!que.empty()) {
            int size = que.size();
            
            while(size--) {
                int i = que.front();
                que.pop();

                if(i == n-1) {
                    return steps;
                }

                if(i-1 >= 0 && !visited[i-1]) {
                    que.push(i-1);
                    visited[i-1] = true;
                }

                if(i+1 <= n-1 && !visited[i+1]) {
                    que.push(i+1);
                    visited[i+1] = true;
                }

                if(!isPrime[nums[i]] || seen.count(nums[i])) {
                    continue;
                }

                for(int multiple = nums[i]; multiple <= maxEl; multiple += nums[i]) {
                    if(!mp.count(multiple)) {
                        continue;
                    }

                    for(int &j : mp[multiple]) {
                        if(!visited[j]) {
                            que.push(j);
                            visited[j] = true;
                        }
                    }
                }

                seen.insert(nums[i]);
            }

            steps++;
        }

        return steps;
    }
};


int main(){

return 0;
}