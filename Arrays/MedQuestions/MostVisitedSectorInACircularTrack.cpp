#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> sectorFreq(n + 1, 0);
        int m = rounds.size();
        int maxFreq = 0;

        for (int i = 1; i < m; ++i) {
            int start = rounds[i - 1];
            int end = rounds[i];
            while (start != end) {
                sectorFreq[start]++;
                maxFreq = max(maxFreq, sectorFreq[start]);
                start = start % n + 1;
            }
        }
        sectorFreq[rounds.back()]++;
        maxFreq = max(maxFreq, sectorFreq[rounds.back()]);

        vector<int> result;
        for (int i = 1; i <= n; ++i) {
            if (sectorFreq[i] == maxFreq) {
                result.push_back(i);
            }
        }
        return result;
    }
};


int main(){

return 0;
}