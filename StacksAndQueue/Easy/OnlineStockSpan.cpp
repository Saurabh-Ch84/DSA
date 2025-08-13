#include<iostream>
#include<stack>
using namespace std;

class StockSpanner {
    stack<pair<int,int>> monoDecStack;
public:
    StockSpanner() {}
    
    int next(int price) {
        pair<int,int> priceSpan={price,1};
        while(!monoDecStack.empty() && price>=monoDecStack.top().first){
            priceSpan.second+=monoDecStack.top().second;
            monoDecStack.pop();
        }
        monoDecStack.push(priceSpan);
        return priceSpan.second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main(){

return 0;
}