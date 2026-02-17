#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution1 {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        map<int,int> events;
        for(vector<int> &a: arr){
            events[a[0]]++;
            events[a[1]]--;
        }
        int cumSum=0;
        for(auto &p: events){
            cumSum+=p.second;
            if(cumSum>1) return false;
        }
        return true;
    }
};

class Solution2 {
public:
    int reverseBits(int n) {
        int num=0;
        for(int i=0;i<32;i++){
            int bit=(n>>i) & 1;
            num=(num<<1) | bit;
        }
        return num;
    }
};

int main(){

return 0;
}