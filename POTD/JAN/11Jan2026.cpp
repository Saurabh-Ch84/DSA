#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int minWindowStart = -1;
        int minWindowLength = n + 1;

        int s1Index = 0, s2Index = 0;

        while (s1Index < n) {
            if (s1[s1Index] == s2[s2Index]) {
                s2Index++;
                if(s2Index == m) {
                    int end = s1Index;
                    int s2BackTrackIndex = m - 1;
                    while (s2BackTrackIndex >= 0) {
                        if (s1[s1Index] == s2[s2BackTrackIndex])
                            s2BackTrackIndex--;
                        s1Index--;
                    }
                    s1Index++;
                    int len = end - s1Index + 1;
                    if (len < minWindowLength) {
                        minWindowLength = len;
                        minWindowStart = s1Index;
                    }
                    s2Index = 0;
                }
            }
            s1Index++;
        }
        return (minWindowStart == -1) ? "" : s1.substr(minWindowStart, minWindowLength);
    }
};

int main(){

return 0;
}