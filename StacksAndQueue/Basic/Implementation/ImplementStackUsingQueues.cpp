#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class MyStack {
    queue<int> q1, q2;
public:
    MyStack() {}
    
    void push(int x) {
        if(!q1.empty()){
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
            q2=q1;
            q1=queue<int>();
        }
        q1.push(x);
    }
    
    int pop() {
        int x=q1.front(); q1.pop();
        if(!q2.empty()){
            int y=q2.front(); q2.pop();
            q1.push(y);
        }
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

class MyStack {
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
        int count=q.size();
        while(count>1){
            q.push(q.front());
            q.pop();
            count--;
        }
    }
    
    int pop() {
        int x=q.front(); q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(){

return 0;
}