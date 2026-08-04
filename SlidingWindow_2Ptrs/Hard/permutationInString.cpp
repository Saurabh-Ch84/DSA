#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
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

class Solution2 {
    using vint=vector<int>;
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length(), m=s2.length();
        if(n>m) return false;

        vint freqArr(26,0);
        int count=0;
        for(int i=0;i<n;i++){
            int idx=s1[i]-'a';
            freqArr[idx]--;
            count--;
        }
        for(int i=0;i<n;i++){
            int idx=s2[i]-'a';
            if(freqArr[idx]<0) count++;
            freqArr[idx]++;
        }
        if(!count) return true;
        for(int i=n;i<m;i++){
            int leftCharIdx=s2[i-n]-'a';
            int rightCharIdx=s2[i]-'a';
            freqArr[leftCharIdx]--;
            if(freqArr[leftCharIdx]<0) count--;
            if(freqArr[rightCharIdx]<0) count++;
            freqArr[rightCharIdx]++;
            if(!count) return true;
        }
        return false;
    }
};

int main(){

return 0;
}