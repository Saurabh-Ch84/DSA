#include<iostream>
#include<stack>
using namespace std;

//optimal approach striver's version
class MinStack {
    stack<long long> st;
    long long minElement;
public:
    MinStack() {
        while (!st.empty()) st.pop();
        minElement = -1;
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minElement = val;
        } else {
            if (val >= minElement) {
                st.push(val);
            } else {
                // Encode the value to store previous min
                st.push(2LL * val - minElement);
                minElement = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long topElement = st.top();
        st.pop();

        if (topElement < minElement) {
            // Recover the previous minElement
            minElement = 2 * minElement - topElement;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long topElement = st.top();
        if (topElement >= minElement) {
            return topElement;
        } else {
            // Decoded top value is minElement
            return minElement;
        }
    }

    int getMin() {
        if (st.empty()) return -1;
        return minElement;
    }
};

// using stack of pairs better approach
class MinStack 
{
    stack<pair<int,int>> s;
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x){
        int minV= (!s.empty() && s.top().second<x) ? s.top().second : x ;
        s.push({x,minV});
    }

    void pop(){
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }
};


//using nothing completely manual
class Solution {
    class Node{
        int val,minVal;
            public:
        Node *prev;
        Node(int val=0){
            this->val=val;
            minVal=val;
            prev=nullptr;
        }
        int getVal(){
            return val;
        }
        int getMinVal(){
            return minVal;
        }
        void setMinVal(int x){
            minVal=x;
        }
        ~Node()=default ;
    };
  public:
    Node *top;
    Solution() {
        // code here
        top=nullptr;
    }
    bool isEmpty(){
        return top==nullptr;
    }
    // Add an element to the top of Stack
    void push(int x) {
        // code here
        Node * temp=new Node(x);
        if(!isEmpty())
        {
            temp->prev=top;
            int mini=min(x,top->getMinVal());
            temp->setMinVal(mini);
        }
        top=temp;
    }
    // Remove the top element from the Stack
    void pop() {
        // code here
        if(isEmpty()) return;
        Node * temp=top;
        top=top->prev;
        temp->prev=nullptr;
        delete temp;
    }
        
    // Returns top element of the Stack
    int peek() {
        // code here
        if(isEmpty()) return -1;
        return top->getVal();
    }
    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(isEmpty()) return -1;
        return top->getMinVal();
    }
};

int main(){

return 0;
}