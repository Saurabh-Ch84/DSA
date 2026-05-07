#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool tryWithAll(vector<int> &start,string &s,string &goal,int n){
        for(int &indice: start){
            int j=indice;
            bool flag=true;
            for(int i=0;i<n;i++){
                if(s[j]!=goal[i]){
                    flag=false;
                    break;
                }
                j=(j+1)%n;
            }
            if(flag) return true;
        }
        return false;
    }
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        int n=s.length();
        vector<int> start;
        for(int i=0;i<n;i++){
            if(s[i]==goal[0])
                start.push_back(i);
        }
        return tryWithAll(start,s,goal,n);
    }
};

class Solution {
    struct Comp {
        // Added 'const' to the end to satisfy strict C++ compiler rules
        bool operator()(const int &a, const int &b) const {
            // Using the blazing-fast hardware-level bit counter
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            // Return true ONLY if A has strictly more bits than B
            // stable_sort handles the ties automatically!
            return countA > countB; 
        }
    };
public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // Swapped to stable_sort to maintain relative order of ties
        stable_sort(arr.begin(), arr.end(), Comp());
        return arr;
    }
};

int main(){

return 0;
}