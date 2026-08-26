#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> stack_in, stack_out;
public:
    MyQueue() {}
    
    void push(int x) {
        stack_in.push(x);
    }
    
    int pop() {
        int ele=peek();
        stack_out.pop();
        return ele;
    }
    
    int peek() {
        if(stack_out.empty()){
            while(!stack_in.empty()){
                int ele=stack_in.top();
                stack_in.pop();
                stack_out.push(ele);
            }
        }
        int ele=stack_out.top();
        return ele;
    }
    
    bool empty() {
        return (stack_in.empty() && stack_out.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){

return 0;
}