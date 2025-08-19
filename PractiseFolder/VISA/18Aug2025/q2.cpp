#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    Given a number in string form, replace consecutive equal digits with their sum until no 
    consecutive digits remain (e.g., "66644319333" → "26328").
*/

class Solution{
        public:
    string operation(string s) {
        bool isConsFound = true;
        while (isConsFound) {
            isConsFound = false;
            string res = "";
            int n = s.length();
            int i = 0;
            while (i < n) {
                char curr = s[i];
                int count = 1;
                int j = i + 1;
                while (j < n && s[j] == curr) {
                    count++;
                    j++;
                }
                if (count > 1) 
                {
                    isConsFound = true;
                    int sum = (curr - '0') * count;
                    res += to_string(sum);
                } 
                else  res += curr;
                i = j; // Move to next group
            }
            s = res;
        }
        return s;
    }
};

int main(){
    Solution s;
    string str;
    cout<<"Enter the number: ";
    cin>>str;
    cout<<"Before Operation: ";
    cout<<str<<endl;
    cout<<"After Operation: ";
    cout<<s.operation(str)<<endl;
return 0;
}