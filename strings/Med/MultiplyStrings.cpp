#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    string add(string &a,string &b){
        if(a.empty()) return b;
        if(b.empty()) return a;
        int n=a.length(),m=b.length();
        string c;
        int left=n-1,right=m-1,carry=0;
        while(left>=0 || right>=0 || carry>0){
            int a_=(left>=0)? a[left--]-'0':0;
            int b_=(right>=0)? b[right--]-'0':0;
            int c_=a_+b_+carry;
            carry=c_/10;
            c_=c_%10;
            c.push_back(c_+'0');
        }
        reverse(begin(c),end(c));
        return c;
    }
public:
    string multiply(string num1, string num2) {
        if(num1[0]=='0' || num2[0]=='0') return "0";
        int n=num1.length(),m=num2.length();
        string result;
        int right=m-1,count=0;
        while(right>=0){
            int n2=num2[right]-'0',carry=0;
            string temp;
            for(int i=n-1;i>=0;i--){
                int q=n2*(num1[i]-'0')+carry;
                carry=q/10;
                q=q%10;
                temp.push_back(q+'0');
            }
            if(carry) temp.push_back(carry+'0');
            reverse(begin(temp),end(temp));
            for(int i=0;i<count;i++) temp.push_back('0');
            result=add(result,temp);
            count++;
            right--;
        }
        return result;
    }
};

int main(){
    Solution s;
    cout<<s.multiply("9831533373606290500873","827606209708336826321");
return 0;
}