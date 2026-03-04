#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

using vi=vector<int>;
using pdi=pair<double,int>;
using vpdi=vector<pdi>;

class Solution1 {
    struct Comp{
        const vi &wt;
        Comp(const vi &wt): wt(wt){}
        bool operator()(const pdi &a, const pdi &b) const{
            double vA=a.first, vB=b.first;
            if (fabs(a.first - b.first) < 1e-9)
                return wt[a.second] < wt[b.second];
            return vA>vB;
        }
    };
  public:
    double fractionalKnapsack(vi val,vi & wt,int capacity) {
        // code here
        int n=wt.size();
        vpdi arr;
        for(int i=0;i<n;i++)
            arr.push_back({(1.0*val[i])/wt[i],i});
        
        sort(arr.begin(),arr.end(),Comp(wt));
        double cap=1.0*capacity, total=0.0;
        for(auto &p: arr){
            if(cap>=1.0*wt[p.second]){
                total+=val[p.second];
                cap-=wt[p.second];
            }
            else{
                total+=p.first*cap;
                break;
            }
        }
        
        return total;
    }
};


class Solution2 {
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