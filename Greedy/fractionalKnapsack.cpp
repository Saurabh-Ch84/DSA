#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double,int>> valuePerWeight;
        int n=val.size();
        for(int i=0;i<n;i++)
        {
            double d=(double)val[i]/wt[i];
            valuePerWeight.push_back({d,i});
        }
        sort(valuePerWeight.begin(),valuePerWeight.end(),[&](pair<double,int> a,pair<double,int> b){
            if(a.first==b.first) return wt[a.second]<wt[b.second];
            return a.first>b.first;
        });
        double value=0.0,cap=(double)capacity;
        for(pair<double,int> &p:valuePerWeight){
            if(cap>=wt[p.second])
            {
                value+=val[p.second];
                cap-=wt[p.second];
            }
            else
            {
                value+=p.first*cap;
                break;
            }
        }
        return value;
    }
};


int main(){

return 0;
}