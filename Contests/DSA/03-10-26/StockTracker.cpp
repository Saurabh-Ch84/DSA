#include <bits/stdc++.h>
using namespace std;

class StockTracker {
    /**
                Problem: Design a Real-Time Stock Tracker
    Design a data structure that tracks stock prices in real-time and supports updating prices, removing stocks, and quickly querying the highest-priced stock.

    Implement the StockTracker class:
        1. StockTracker() Initializes the object with no tracked stocks.
        2. void addOrUpdateStock(string symbol, int price) Adds a stock with its price, or updates its price if it already exists.
        3. int getPrice(string symbol) Returns the current price of symbol. If the stock is not being tracked, return -1.
        4. void removeStock(string symbol) Removes symbol from tracking. If it is not present, do nothing.
        5. string getHighestStock() Returns the symbol of the stock with the highest price. 
        If there is a tie, return the lexicographically smaller symbol. If no stocks are tracked, return "".
     
     * Your StockTracker object will be instantiated and called as such:
     * StockTracker* obj = new StockTracker();
     * obj->addOrUpdateStock(symbol, price);
     * int param_2 = obj->getPrice(symbol);
     * obj->removeStock(symbol);
     * string param_4 = obj->getHighestStock();
     */
    struct Comp{
        bool operator()(const pair<int,string> &a, const pair<int,string> &b) const{
            int priceA=a.first, priceB=b.first;
            if(priceA!=priceB){
                return priceA<priceB;
            }
            string symbolA=a.second, symbolB=b.second;
            return symbolA>symbolB;
        }
    };
    unordered_map<string,int> stockMap;
    priority_queue<pair<int,string>,vector<pair<int,string>>,Comp> maxHeap;
    bool isInvalid(){
        string symbol=maxHeap.top().second;
        return (!stockMap.count(symbol) || stockMap[symbol]!=maxHeap.top().first);
    }
public:
    StockTracker() {}
    
    void addOrUpdateStock(string symbol, int price) {
        stockMap[symbol]=price;
        maxHeap.push({price,symbol});
    }
    
    int getPrice(string symbol) {
        return (stockMap.count(symbol)? stockMap[symbol]:-1);
    }
    
    void removeStock(string symbol) {
        stockMap.erase(symbol);
    }
    
    string getHighestStock() {
        while(!maxHeap.empty() && isInvalid()){
            maxHeap.pop();
        } 
        return (maxHeap.empty()? "":maxHeap.top().second);
    }
};

int main(){
    StockTracker* tracker = new StockTracker();
    tracker->addOrUpdateStock("AAPL", 150);  // AAPL: 150
    tracker->addOrUpdateStock("GOOG", 2800); // AAPL: 150, GOOG: 2800
    cout<<tracker->getHighestStock()<<endl;  // Returns "GOOG" (2800)
    cout<<tracker->getPrice("AAPL")<<endl;   // Returns 150
    tracker->addOrUpdateStock("AAPL", 3000); // AAPL: 3000, GOOG: 2800
    cout<<tracker->getHighestStock()<<endl;  // Returns "AAPL" (3000)
    tracker->removeStock("AAPL");            // AAPL removed
    cout<<tracker->getHighestStock()<<endl;  // Returns "GOOG" (2800)
    return 0;
}