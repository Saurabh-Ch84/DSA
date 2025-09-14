#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string res;
        int n=s.length();
        for(int i=0;i<numRows;i++){
            int j=i;
            int turnLeft=2*(numRows-1-i),turnRight=2*i;
            bool goingDown=true;
            while(j<n){
                res.push_back(s[j]);
                if(i==0) j+=turnLeft;
                else if(i==numRows-1) j+=turnRight;
                else{
                    j+=(goingDown)? turnLeft:turnRight;
                    goingDown=!goingDown;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    cout<<s.convert("saurabhishere",3);
return 0;
}