#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;

class FreqStack {
    unordered_map<int,int> valToFreq;
    unordered_map<int,stack<int>> freqToStackOfVal;
    int maxFreq;
        public:
        
    FreqStack():maxFreq(0) {}
    
    void push(int val) {
        int frequency=++valToFreq[val];
        freqToStackOfVal[frequency].push(val);
        maxFreq=max(maxFreq,frequency);
    }
    
    int pop() {
        int val=freqToStackOfVal[maxFreq].top();
        freqToStackOfVal[maxFreq].pop();
        if(freqToStackOfVal[maxFreq].empty())
            freqToStackOfVal.erase(maxFreq--);
        if(--valToFreq[val]==0) valToFreq.erase(val);
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */


int main(){

return 0;
}