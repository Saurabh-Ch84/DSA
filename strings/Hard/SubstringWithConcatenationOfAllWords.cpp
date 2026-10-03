#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> hashMap;
        int len=words[0].size(), n=s.size(), numWords=words.size();
        
        for(string &word: words) 
            hashMap[word]++;

        vector<int> res;
        // Outer loop to only run 'len' times (the offsets)
        for(int i=0; i<len; i++){
            unordered_map<string,int> tempMap;
            int start = i, count = 0; // count tracks total valid words in current window
            // 2. Slide 'j' forward by 'len' instead of re-looping from scratch
            for(int j=i; j<=n-len; j+=len){
                string currWindow=s.substr(j,len);
                if(hashMap.count(currWindow)){
                    tempMap[currWindow]++;
                    count++;
                    // 3. If we found too many of the current word, slide 'start' forward to fix it
                    while(tempMap[currWindow] > hashMap[currWindow]){
                        string leftWord = s.substr(start, len);
                        tempMap[leftWord]--;
                        count--;
                        start += len;
                    }
                    // 4. If our valid word count matches the total required words, we found a target!
                    if(count == numWords) res.push_back(start);
                }
                else {
                    // Invalid word breaks the streak: instantly reset the map and pointers
                    tempMap.clear();
                    count = 0;
                    start = j + len;
                }
            }
        }
        return res;
    }
};

int main(){

return 0;
}