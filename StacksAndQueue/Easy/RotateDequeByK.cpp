#include<iostream>
#include<deque>
using namespace std;

class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        while(k--){
            if(type==1){
                int temp=dq.back();
                dq.pop_back();
                dq.push_front(temp);
            }
            else{
                int temp=dq.front();
                dq.pop_front();
                dq.push_back(temp);
            }
        }
    }
};

int main(){

return 0;
}