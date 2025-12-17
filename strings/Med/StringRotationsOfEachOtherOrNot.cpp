#include<iostream>
#include<vector>

using namespace std;

class Solution {
    vector<int> computeLPS(string &s2,int patternLen){
        vector<int> lps(patternLen,0);
        int len=0,i=1;
        while(i<patternLen){
            if(s2[i]==s2[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len) len=lps[len-1];
                else i++;
            }
        }
        return lps;
    }
    
    bool KMP(string &temp,string &s2){
        int patternLen=s2.size(),textLen=temp.size();
        vector<int> lps=computeLPS(s2,patternLen);
        int i=0,j=0;
        while(i<textLen){
            if(temp[i]==s2[j]){
                j++;
                if(j==patternLen) return true;
                i++;
            }
            else{
                if(j) j=lps[j-1];
                else i++;
            }
        }
        return false;
    }
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        if(s1.size()!=s2.size()) 
            return false;
        string temp=s1+s1;
        return KMP(temp,s2);
    }
};

int main(){

return 0;
}