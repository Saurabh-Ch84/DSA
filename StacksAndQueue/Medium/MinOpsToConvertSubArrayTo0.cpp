#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> monoInStack;
        monoInStack.push(0);
        int ops=0;
        for(int &num: nums){
            while(monoInStack.top()>num)
                monoInStack.pop();
            if(monoInStack.top()<num){
                monoInStack.push(num);
                ops++;
            }
        }
        return ops;
    }
};

int main(){

return 0;
}