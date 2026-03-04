#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string maximumXor(string s, string t) {
        int zeros=0, ones=0, n=s.length();
        for(char bit: t){
            if(bit=='1') ones++;
            else zeros++;
        }

        string res;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(zeros){
                    res.push_back('1');
                    zeros--;
                }
                else{
                    res.push_back('0');
                    ones--;
                }
            }
            else{
                if(ones){
                    res.push_back('1');
                    ones--;
                }
                else{
                    res.push_back('0');
                    zeros--;
                }
            }
        }

        return res;
    }
};

int main(){

return 0;
}