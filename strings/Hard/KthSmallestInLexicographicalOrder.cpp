#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int getChildrenCount(long curr,long next,int n){
        int children=0;
        while(curr<=n){
            children+=next-curr;
            curr=curr*10;
            next=min(next*10,(long)n+1);
        }
        return children;
    }
public:
    int findKthNumber(int n, int k) {
        int curr=1;
        k=k-1;
        while(k>0){
            int childrenCount=getChildrenCount(curr,curr+1,n);
            if(childrenCount<=k){
                curr++;
                k-=childrenCount;
            }
            else{
                curr=curr*10;
                k-=1;
            }
        }
        return curr;
    }
};

int main(){

return 0;
}