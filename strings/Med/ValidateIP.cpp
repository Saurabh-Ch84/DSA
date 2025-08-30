#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string validIPAddress(string queryIP) {
        if(count(queryIP.begin(),queryIP.end(),'.')==3){
            if(queryIP.back()=='.') return "Neither";
            stringstream ssV4(queryIP);
            string token;
            int countSegments=0;
            while(getline(ssV4,token,'.')){
                countSegments++;
                if(!token.length() || token.length()>3) return "Neither";
                if(token[0]=='0' && token.length()>1) return "Neither";
                for(char ch:token)
                    if(!isdigit(ch)) return "Neither";
                if(stoi(token)>255) return "Neither";
            }
            return countSegments==4?"IPv4":"Neither";
        }
        else if(count(queryIP.begin(),queryIP.end(),':')==7){
            if(queryIP.back()==':') return "Neither";
            stringstream ssV6(queryIP);
            string token;
            int countSegments=0;
            while(getline(ssV6,token,':')){
                if(!token.length() || token.length()>4) return "Neither";
                for(char ch:token)
                    if(!isxdigit(ch)) return "Neither";
                countSegments++;
            }
            return countSegments==8?"IPv6":"Neither";
        }
        return "Neither";
    }
};

int main(){
    Solution s;
    string ip1="2405:201:8002:4133:14e4:9ebf:cc66:893d";
    string ip2="192.168.29.1";
    cout<<s.validIPAddress(ip1)<<endl;
    cout<<s.validIPAddress(ip2)<<endl;
return 0;
}