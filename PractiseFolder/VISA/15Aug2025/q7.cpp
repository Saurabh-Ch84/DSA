#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestWindow(string &s1, string &s2) {
        int n = s1.length(), m = s2.length();
        if (n == 0 || m == 0 || m > n) return "";

        unordered_map<char, int> window, freq;
        int required = 0;
        for (char ch : s2) {
            if (freq[ch] == 0) required++;
            freq[ch]++;
        }

        int left = 0, right = 0, start = -1, minLen = n + 1, formed = 0;
        while (right < n) {
            char curr = s1[right];
            window[curr]++;
            if (freq.count(curr) && window[curr] == freq[curr])
                formed++;

            while (formed == required){
                if (minLen > right - left + 1) {
                    start = left;
                    minLen = right - left + 1;
                }
                char prev = s1[left++];
                window[prev]--;
                if (freq.count(prev) && window[prev] < freq[prev])
                    formed--;
            }
            right++;
        }
        if (start == -1) return "";
        return s1.substr(start, minLen);
    }
};

int main(){
    Solution s;
    string str="timetopractice";
    string tar="toc";
    cout<<s.smallestWindow(str,tar)<<endl;
return 0;
}