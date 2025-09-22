#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    Q1: Enter two numbers N and x. If x is even then print the sum of odd position numbers present in N and if x is odd then print the sum of odd position numbers present in N. 
    (The question was not written directly like this. It was a long question which had this logic behind) 
    Test case 1: Input: N= 1250, x=2; Output: 6 Test Case 2: Input: N=128456, x=7; Output: 12. 

    Q2: Enter two words String1 and String2 and return the sum with more weight. If weights are same then return -1. Weight is the sum of ASCII values of the alphabets in the string. 
    Test Case 1: Input:String 1 - say, String 2 - ball . Output: 45 Explanation: say(s-19, a-1, y-25) sum is 45, ball(b-2, a-1, l-12) sum is 27 ; Weight=45 
*/

class Solution{
    int findWeight(string num){
        int weight=0;
        for(char letter:num)
            weight+=letter-'a'+1;
        return weight;
    }
        public:
    int q1(int N,int x){
        string number=to_string(N);
        bool even=(x%2==0);
        int sum=0,n=number.length();
        for(int i=0;i<n;i++){
            if(even && i%2==0){
                sum+=number[i]-'0';
            }
            else if(!even && i%2==1){
                sum+=number[i]-'0';
            }
        }
        return sum;
    }

    int q2(string a,string b){
        int weightA=findWeight(a),weightB=findWeight(b);    
        return max(weightA,weightB);
    }
};

int main(){
    Solution s;
    cout<<s.q1(128456,7)<<endl;
    cout<<s.q2("say","ball")<<endl;
return 0;
}