#include<iostream>
#include<vector>
#include<list>
using namespace std;

class MyCircularDeque {
    list<int> dll;
    int currSize, totalSize;
public:
    MyCircularDeque(int k) {
        currSize=0;
        totalSize=k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        dll.push_front(value);
        currSize++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        dll.push_back(value);
        currSize++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        dll.pop_front();
        currSize--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        dll.pop_back();
        currSize--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return dll.front();
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return dll.back();
    }
    
    bool isEmpty() {
        return (currSize==0);
    }
    
    bool isFull() {
        return (currSize==totalSize);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

 class MyCircularDeque {
    vector<int> deq;
    int front, rear;
    int currSize, totalSize;
public:
    MyCircularDeque(int k) {
        totalSize=k, currSize=0;
        front=0, rear=k-1;
        deq.assign(k,-1);
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        front=(front-1+totalSize)%totalSize;
        deq[front]=value;
        currSize++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        rear=(rear+1)%totalSize;
        deq[rear]=value;
        currSize++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        front=(front+1)%totalSize;
        currSize--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        rear=(rear-1+totalSize)%totalSize;
        currSize--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return deq[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return deq[rear];
    }
    
    bool isEmpty() {
        return (currSize==0);
    }
    
    bool isFull() {
        return (currSize==totalSize);
    }
};


int main(){

return 0;
}