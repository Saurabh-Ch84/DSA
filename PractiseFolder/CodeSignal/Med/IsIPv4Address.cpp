#include<iostream>
#include<sstream>
using namespace std;

/*
### Problem Statement

**An IP address is a numerical label assigned to each device (e.g., computer, printer) participating in a computer network that uses the Internet Protocol for communication. There are two versions of the Internet protocol, and thus two versions of addresses. One of them is the IPv4 address.**

**Given a string, find out if it satisfies the IPv4 address naming rules.**

#### Example

- For `inputString = "172.16.254.1"`, the output should be  
  `isIPv4Address(inputString) = true`

- For `inputString = "172.316.254.1"`, the output should be  
  `isIPv4Address(inputString) = false`  
  `316` is not in range `[0, 255]`.

- For `inputString = ".254.255.0"`, the output should be  
  `isIPv4Address(inputString) = false`
*/class Solution {
    int countDots(string str) {
        int count = 0;
        for(char ch: str)
            if(ch == '.') count++;
        return count;
    }
public:
    bool isIPv4Address(string str) {
        if(countDots(str) != 3) return false;
        stringstream ss(str);
        string token;
        int segments = 0;
        while(getline(ss, token, '.')) {
            segments++;
            if(token.empty()) return false;
            if(token.size() > 3) return false;
            if(token.size() > 1 && token[0] == '0') return false;
            for(char ch: token) {
                if(ch < '0' || ch > '9') return false;
            }
            int seg = stoi(token);
            if(seg < 0 || seg > 255) return false;
        }
        return segments == 4;
    }
};


int main(){
    Solution s;
    cout<<s.isIPv4Address("172.16.254.1")<<endl;
    cout<<s.isIPv4Address("172.316.254.1")<<endl;
    cout<<s.isIPv4Address(".254.255.0")<<endl;
return 0;
}