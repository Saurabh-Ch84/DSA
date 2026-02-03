#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
public:
    // difference Array technique
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> population(101,0);
        for(vector<int> &log: logs){
            int st=log[0], end=log[1];
            population[st-1950]++;
            population[end-1950]--;
        }
        int maxPopulation=0, year=-1;
        for(int i=0;i<101;i++){
            population[i]+=(i? population[i-1]:0);
            if(maxPopulation<population[i]){
                maxPopulation=population[i];
                year=i+1950;
            }
        }
        return year;
    }
};

class Solution2 {
public:
    // Line Sweep Technique
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>> events;
        for(vector<int> &log: logs){
            events.push_back({log[0],1});
            events.push_back({log[1],-1});
        }
        sort(events.begin(),events.end());
        int currPop=0, maxPop=0, maxYear=0;
        for(auto &event: events){
            currPop+=event.second;
            if(currPop>maxPop){
                maxPop=currPop;
                maxYear=event.first;
            }
        }
        return maxYear;
    }
};

int main(){

return 0;
}