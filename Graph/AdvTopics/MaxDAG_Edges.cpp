#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        int curEdges=edges.size();
        int maxEdges=(V*(V-1))/2;
        int addEdges=maxEdges-curEdges;
        return addEdges;
    }
};


int main(){

return 0;
}