#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        // code here
        sort(chairs.begin(),chairs.end());
        sort(passengers.begin(),passengers.end());
        
        int moves=0,n=chairs.size(),ptr=0;
        while(ptr<n){
            moves+=abs(chairs[ptr]-passengers[ptr]);
            ptr++;
        }
        return moves;
    }
};

int main(){

return 0;
}