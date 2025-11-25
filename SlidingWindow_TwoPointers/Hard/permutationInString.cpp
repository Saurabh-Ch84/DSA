#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        if(n>m) return false;
        vector<int> freqArr1(26,0),freqArr2(26,0);
        for(int i=0;i<n;i++){
            freqArr1[s1[i]-'a']++;
            freqArr2[s2[i]-'a']++;
        }
        int left=0,right=n;
        while(right<m){
            if(freqArr1==freqArr2) return true;
            freqArr2[s2[left]-'a']--;
            left++;
            freqArr2[s2[right]-'a']++;
            right++;
        }
        return freqArr1==freqArr2;
    }
};

int main(){

return 0;
}