#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long sum=0;
        int n=balance.size();
        int negIdx=-1;
        for(int i=0;i<n;i++){
            if(balance[i]<0) negIdx=i;
            sum+=balance[i];
        }
        if(sum<0) return -1;
        if(negIdx==-1) return 0;

        long long moves=0;
        int distance=1;
        while(balance[negIdx]<0){
            int left=(negIdx-distance+n)%n;
            int right=(negIdx+distance)%n;
            long long total=0;
            if(left==right) total+=balance[left];
            else total+=balance[left]+balance[right];
            long long mini=min(-1LL*balance[negIdx],total);
            balance[negIdx]+=(int)mini;
            moves+=distance*mini;
            distance++;
        }
        return moves;
    }
};

int main(){

return 0;
}