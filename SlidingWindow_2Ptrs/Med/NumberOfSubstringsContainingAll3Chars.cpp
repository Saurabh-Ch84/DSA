#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// most optimal solution
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastOccArr(3,-1);
        int n=s.length(),count=0;
        for(int i=0;i<n;i++){
            lastOccArr[s[i]-'a']=i;
            if(lastOccArr[0]!=-1 && lastOccArr[1]!=-1 && lastOccArr[2]!=-1) 
                count+=min({lastOccArr[0],lastOccArr[1],lastOccArr[2]})+1;
        }
        return count;
    }
};

//my version
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length(),left=0,right=0;
        unordered_map<char,int> freqMap;
        int count=0;
        while(right<n){
            freqMap[s[right]]++;
            while(freqMap.size()==3){
                count+=n-right;
                freqMap[s[left]]--;
                if(freqMap[s[left]]==0)
                    freqMap.erase(s[left]);
                left++;
            }
            right++;
        }
        return count;
    }
};

int main(){

return 0;
}