#include<iostream>
#include<queue>
using namespace std;

class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        priority_queue<double> pq;
        double sum=0.0;
        for(int &e: arr){
            sum+=e;
            pq.push(e);
        }
        
        double half=sum/2.0;
        int steps=0;
        while(sum>half){
            steps++;
            double top=pq.top();
            pq.pop();
            top=top/2.0;
            sum-=top;
            pq.push(top);
        }
        
        return steps;
    }
};

int main(){

return 0;
}