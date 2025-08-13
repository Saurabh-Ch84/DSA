#include<iostream>
using namespace std;

class Queue1{
    int *arr;
    int top, rear, s;
public:
    Queue1(int size=100){
        s = size;
        arr = new int[s];
        top = -1;
        rear = -1;
    }
    void push(int num){
        if(rear == s-1){
            cout << "OverFlow" << endl;
            return;
        }
        arr[++rear] = num;
        if(top == -1) top = rear;
    }
    void pop(){
        if(top == -1 || top > rear){
            cout << "UnderFlow" << endl;
            return;
        }
        top++;
        if(top > rear){ // Reset to initial state when empty
            top = rear = -1;
        }
    }
    int front(){
        if(top == -1 || top > rear){
            cout << "UnderFlow" << endl;
            return -1;
        }
        return arr[top];
    }
    int size() const{
        if(top == -1) return 0;
        return rear - top + 1;
    }
    ~Queue1() {
        delete[] arr;
    }
};

class CircularQueue {
    int *arr;
    int front, rear, s;
        public:
    CircularQueue(int size = 100) {
        s = size;
        arr = new int[s];
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == (rear + 1) % s);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void push(int num) {
        if (isFull()) {
            cout << "OverFlow" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % s;
        }
        arr[rear] = num;
    }

    void pop() {
        if (isEmpty()) {
            cout << "UnderFlow" << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % s;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "UnderFlow" << endl;
            return -1;
        }
        return arr[front];
    }

    int size() const {
        if (front == -1) return 0;
        if (rear >= front) return rear - front + 1;
        return s - front + rear + 1;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

class Queue{
    class Node{
            public:
        int val;
        Node *next;
        Node(int val=0){
            this->val=val;
            next=nullptr;
        }
        ~Node(){
            delete next;
        }
    };
    int s;
    Node *f,*r;
        public: 
    Queue(){
        f=nullptr;
        r=nullptr;
        s=0;
    }
    void push(int n){
        if(isEmpty()){
            r=new Node(n);
            f=r;
        }
        else{
            r->next=new Node(n);
            r=r->next;
        }
        s++;
    }

    bool isEmpty(){
        return f==nullptr;
    }
    int front(){
        if(isEmpty()){
            cout<<"UnderFlow"<<endl;
            return -1;
        }
        return f->val;
    }
    void pop(){
        if(isEmpty()){
            cout<<"UnderFlow"<<endl;
            return ;
        }
        Node * temp=f;
        f=f->next;
        temp->next=nullptr;
        delete temp;
        s--;
        if(isEmpty()) r=nullptr;
    }
    int size(){
        return s;
    }
    ~Queue(){
        delete f;
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.push(50);
    q.push(60);
    q.push(70);
    cout << "Queue size: " << q.size() << endl;

    while (!q.isEmpty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
