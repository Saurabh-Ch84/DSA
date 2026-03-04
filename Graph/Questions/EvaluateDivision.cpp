#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

using vvs=vector<vector<string>>;

class Solution {
    using memo_t=unordered_map<int,unordered_map<int,double>>;
public:
    vector<double> calcEquation(vvs &equations,vector<double>& values,vvs &queries) {
        memo_t dist;
        unordered_map<string,int> hashMap;
        int n=values.size();

        for(int i=0;i<n;i++){
            string U=equations[i][0], V=equations[i][1];
            if(!hashMap.count(U))
                hashMap[U]=hashMap.size();
            if(!hashMap.count(V))
                hashMap[V]=hashMap.size();

            int u=hashMap[U], v=hashMap[V];
            dist[u][u]=1.0;
            dist[v][v]=1.0;

            double w=values[i];
            dist[u][v]=w;
            dist[v][u]=1/w;
        }

        // 2. Floyd-Warshall Algorithm (The ultimate cache builder)
        // If we know A -> K and K -> B, then A -> B is (A->K) * (K->B)
        for (auto& k_pair : dist) {
            int k = k_pair.first;
            for (auto& i_pair : dist) {
                int i = i_pair.first;
                for (auto& j_pair : dist) {
                    int j = j_pair.first;
                    // If i->k exists and k->j exists, we can cache i->j
                    if (dist[i].count(k) && dist[k].count(j)) {
                        dist[i][j] = dist[i][k] * dist[k][j];
                    }
                }
            }
        }

        int q=queries.size();
        vector<double> result(q,-1.0);
        for(int i=0;i<q;i++){
            if(!hashMap.count(queries[i][0]) || !hashMap.count(queries[i][1]))
                continue;
            int u=hashMap[queries[i][0]], v=hashMap[queries[i][1]];
            result[i]=(dist[u][v]==0 ? -1.0: dist[u][v]);
        }
        return result;
    }
};

int main(){

return 0;
}