#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        int n=seats.size();
        for(int i=0;i<n-1;i++){
            if(seats[i] && seats[i+1])
                return false;
        }
        int i=0;
        while(i<n){
            if(seats[i]) i+=2;
            else{
                if(i==n-1 || !seats[i+1]){
                    k--;
                    i+=2;
                }
                else i++;
            }
            if(!k) return true;
        }
        return false;
    }
};

int main(){

return 0;
}