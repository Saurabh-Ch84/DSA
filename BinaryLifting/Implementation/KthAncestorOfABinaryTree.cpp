#include<bits/stdc++.h>
using namespace std;

class TreeAncestor {
    using vint = vector<int>;
    using vvint = vector<vint>;
    vvint ancestor;
    int n, m;
public:
    TreeAncestor(int n, vector<int>& parent):n(n),m(ceil(log2(n))+1){
        ancestor.resize(n, vint(m, -1));
        // FIX 2: Delete the DFS! The parent array is ALREADY the 2^0 ancestor.
        for(int i = 0; i < n; i++){
            ancestor[i][0] = parent[i];
        }
        for(int j = 1; j < m; j++){
            for(int i = 0; i < n; i++){
                if(ancestor[i][j-1] != -1)
                    ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int p = 0;
        while(k > 0 && node != -1){
            // Optional Safety: If k is massively larger than the tree, return -1
            if (p >= m) return -1; 
            if(k & 1) node = ancestor[node][p];
            k = k >> 1;
            p++;
        }
        return node;
    }
};

int main(){

return 0;
}