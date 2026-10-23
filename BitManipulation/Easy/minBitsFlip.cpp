#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res=start^goal,answer=0;
        while(res){
            res=res&(res-1);
            answer++;
        }
        return answer;
    }
};

int main(){

return 0;
}