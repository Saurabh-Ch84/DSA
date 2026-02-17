#include<iostream>
#include<vector>
using namespace std;

//Brute-Force
class CustomStack {
    vector<int> st;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
    }
    
    void push(int x) {
        if(st.size()==maxSize) return ;
        st.push_back(x);
    }
    
    int pop() {
        if(st.empty()) return -1;
        int top=st.back();
        st.pop_back();
        return top;
    }
    
    void increment(int k, int val) {
        int n=st.size();
        for(int i=0;i<min(k,n);i++)
            st[i]+=val;
    }
};

// Optimal
class CustomStack {
    vector<int> stArr, incArr;
    int maxSize, ptr;
public:
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
        ptr=0;
        stArr.assign(maxSize,-1);
        incArr.assign(maxSize,0);
    }
    
    void push(int x) {
        if(ptr==maxSize) return ;
        stArr[ptr++]=x;
    }
    
    int pop() {
        if(!ptr) return -1;
        ptr--;
        int top=stArr[ptr];
        int inc=incArr[ptr];
        if(ptr>0) incArr[ptr-1]+=incArr[ptr];
        incArr[ptr]=0;
        return top+inc;
    }
    
    void increment(int k, int val) {
        if(!ptr) return; 
        int i = min(k, ptr) - 1; 
        incArr[i] += val;
    }
};


/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main(){

return 0;
}