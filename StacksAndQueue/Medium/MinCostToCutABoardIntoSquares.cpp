#include<iostream>
#include<queue>
using namespace std;

class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        int hSeg=1,vSeg=1;
        priority_queue<int> pqX(x.begin(),x.end());
        priority_queue<int> pqY(y.begin(),y.end());
        
        int cost=0;
        while(!pqX.empty() || !pqY.empty()){
            int maxi;
            if(!pqX.empty() && !pqY.empty()){
                if(pqX.top()>pqY.top()){
                    maxi=pqX.top();
                    pqX.pop();
                    cost+=maxi*hSeg;
                    vSeg++;
                }
                else{
                    maxi=pqY.top();
                    pqY.pop();
                    cost+=maxi*vSeg;
                    hSeg++;
                }
            }
            else if(pqX.empty()){
                maxi=pqY.top();
                pqY.pop();
                cost+=maxi*vSeg;
                hSeg++;
            }
            else{
                maxi=pqX.top();
                pqX.pop();
                cost+=maxi*hSeg;
                vSeg++;
            }
        }
        return cost;
    }
};

int main(){

return 0;
}