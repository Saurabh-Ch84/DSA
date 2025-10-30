#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int N=target.size(),curr=0,prev=0,count=0;
        for(int i=0;i<N;i++){
            curr=target[i];
            if(curr>prev) count+=curr-prev;
            prev=curr;
        }
        return count;
    }
};

int main(){

return 0;
}