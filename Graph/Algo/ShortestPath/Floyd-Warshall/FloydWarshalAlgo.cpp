#include<iostream>
#include<vector>
using namespace std;

// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int inf=(int)(1e8);
        int n=dist.size();
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=inf && dist[k][j]!=inf)
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i][i]<0) 
                cout<<"Negative Cycle:"; //negative weight cycle found
        }
    }
};

int main(){

return 0;
}