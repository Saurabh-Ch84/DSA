#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string validIPAddress(string queryIP) {
        regex IPv4("^((25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]?|0)\\.){3}"
                   "(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]?|0)$");
        if(regex_match(queryIP,IPv4))
            return "IPv4";
        regex IPv6("^([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$");
        if(regex_match(queryIP,IPv6))
            return "IPv6";
        return "Neither";
    }
};

int main(){

return 0;
}