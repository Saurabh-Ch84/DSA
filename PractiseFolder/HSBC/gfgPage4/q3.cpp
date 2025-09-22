#include<iostream>
using namespace std;

/*
    Given: A=1, B=10, C=100, D=1000, E=10000, F=100000, G=1000000. 
    The input is a string, and the output should be sum of the sequence. 
    For eg: BC=10+100=110.
*/

class Solution{
        public:
    int q(string str){        
        int sum=0,n=str.length();
        for(int i=0;i<n;i++){
            int place=str[i]-'A',num=1;
            for(int j=0;j<place;j++)
                num*=10;
            sum+=num;
        }
        return sum;
    }
};

int main(){
    Solution s;
    cout<<s.q("BC");
return 0;
}