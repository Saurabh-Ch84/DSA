#include<iostream>
#include<algorithm>
using namespace std;

/*
    8. Binary String Addition 
        ○ Given two binary strings, return their sum in string format. 
        ○ Example: "101" + "11" → "1000" 
*/

string binaryAdd(string &num1, string &num2) {
    int carry = 0; // Use int for easier math
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    string res;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';

        // If sum is 0 or 2, bit is '0'. If 1 or 3, bit is '1'.
        res.push_back((sum % 2) + '0'); 
        
        // If sum is 2 or 3, carry becomes 1.
        carry = sum / 2; 
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    string num1;
    cout<<"Enter Num1: ";
    cin>>num1;
    
    string num2;
    cout<<"Enter Num2: ";
    cin>>num2;
    cout<<binaryAdd(num1,num2);
return 0;
}