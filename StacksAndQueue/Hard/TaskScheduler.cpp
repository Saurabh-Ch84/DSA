#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freqMap;
        for(char task: tasks)
            freqMap[task]++;

        priority_queue<int> pq;
        for(auto &p: freqMap)
            pq.push(p.second);

        int minIntervals=0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }
            for(int &freq: temp){
                int newFreq=freq-1;
                if(newFreq) pq.push(newFreq);
            }
            minIntervals=minIntervals + 
                        (pq.empty()? temp.size(): n+1);
        }
        return minIntervals;
    }
};

int main(){

return 0;
}