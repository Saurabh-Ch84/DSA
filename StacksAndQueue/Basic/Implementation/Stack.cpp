#include<iostream>
#include<vector>
using namespace std;

class Stack1{
    int *arr,topIndex=-1,s;
        public:
    Stack1(int size=100){
        arr=new int[size];
        topIndex=-1;
        s=size;
    }
    void push(int num){
        if(topIndex==s-1){
            cout<<"OverFlow_1"<<endl;
            return ;
        }
        arr[++topIndex]=num;
    }
    void pop(){
        if(topIndex<0){
            cout<<"UnderFlow_1"<<endl;
            return ;
        }
        topIndex--;
    }
    int top(){
        if(topIndex<0){
            cout<<"UnderFlow_1"<<endl;
            return -1;
        }
        return arr[topIndex];
    }
    int size(){
        return topIndex+1;
    }

    ~Stack1() {
        delete[] arr;
    }
};

class Stack{
    class Node{
            public:
        int val;
        Node *prev;
        Node(int val=0){
            this->val=val;
            prev=nullptr;
        }
        ~Node(){
            delete prev;
        }
    };
    int s;
    Node *topIdx;
        public:
    Stack(){
        s=0;
        topIdx=nullptr;
    }
    bool isEmpty(){
        return topIdx==nullptr;
    }
    int top(){
        if(isEmpty()){
            cout<<"UnderFlow"<<endl;
            return -1;
        }
        return topIdx->val;
    }
    void push(int n){
        if(isEmpty()){
            topIdx=new Node(n);
        }
        else{
            Node *temp=new Node(n);
            temp->prev=topIdx;
            topIdx=temp;
        }
        s++;
    }
    void pop(){
        if(isEmpty()){
            cout<<"UnderFlow"<<endl;
            return ;
        }
        Node *temp=topIdx;
        topIdx=topIdx->prev;
        temp->prev=nullptr;
        delete temp;
        s--;
    }
    int size(){
        return s;
    }
    ~Stack(){
        delete topIdx;
    }
};

int main(){
    Stack s;
    s.push(9);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.push(2);
    s.push(5);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.size()<<endl;
return 0;
}