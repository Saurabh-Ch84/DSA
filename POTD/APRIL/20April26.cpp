#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
  public:
    int derangeCount(int n) {
        // code here
        if(n==1) return 0;
        if(n==2) return 1;
        int x=0,y=1;
        for(int i=3;i<=n;i++){
            int p=(i-1)*(x+y);
            x=y;
            y=p;
        }
        return y;
    }
};

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxi=0, i=0;
        unordered_map<int,int> hashMap;
        for(int &color: colors){
            for(auto &p: hashMap){
                if(p.first==color) continue;
                maxi=max(maxi,abs(i-p.second));
            }
            if(hashMap.find(color)==hashMap.end()) hashMap[color]=i;
            i++;
        }
        return maxi;
    }
};


int main(){

return 0;
}