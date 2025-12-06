#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

class DetectSquares {
using pii = pair<int,int> ;
using vi = vector<int> ;
    map<pii,int> hashMap;
    unordered_map<int,vi> xMap;

    int horizontal(vi pA,vi pB){
        int x1=pA[0],x2=pB[0],y=pB[1];
        int d=x2-x1,ans=0;
        ans+=hashMap[{x1,y+d}]*hashMap[{x2,y+d}];
        ans+=hashMap[{x1,y-d}]*hashMap[{x2,y-d}];
        return ans;
    }

public:
    DetectSquares(){}
    
    void add(vector<int> point) {
        int x=point[0],y=point[1];
        xMap[y].push_back(x);
        hashMap[{x,y}]++;
    }
    
    int count(vector<int> point) {
        if(hashMap.size()<3) return 0;
        int ans=0,x=point[0],y=point[1];
        vi &xLine=xMap[y];
        for(int x_: xLine){
            if(x_==x) continue;
            ans+=horizontal(point,{x_,y});
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

int main(){

return 0;
}