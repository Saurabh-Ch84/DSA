#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool isPrefixAndSuffix(string &s1,string &s2){
        int n=s1.length(), m=s2.length();
        if(n>m) return false;

        int i=0, j=0;
        while(i<n){
            if(s1[i]!=s2[j]) return false;
            i++, j++;
        }

        int i_=n-1, j_=m-1;
        while(i_>=0){
            if(s1[i_]!=s2[j_]) return false;
            i_--, j_--;
        }

        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size(), count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isPrefixAndSuffix(words[i],words[j]))
                    count++;
            }
        }
        return count;
    }
};

int main(){

return 0;
}