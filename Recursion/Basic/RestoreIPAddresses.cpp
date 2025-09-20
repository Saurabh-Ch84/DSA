#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// AI's code
class Solution1 {
    bool isValid(const string &seg){
        if(seg.size()==0) return false;
        if(seg[0]=='0' && seg.size()>1) return false;
        int segNum=stoi(seg);
        return segNum<=255;
    }
    void recursion(string &s,int i,int n,vector<string> &result,string ip,int segCount){
        if(i==n && segCount==4){
            result.push_back(ip);
            return ;
        }
        if(i>=n || segCount>=4) return ;
        for(int j=i;j<min(i+3,n);j++){
            string seg=s.substr(i,j-i+1);
            if(!isValid(seg)) continue;
            string ip_=(ip.empty())? seg: ip+'.'+seg;
            recursion(s,j+1,n,result,ip_,segCount+1);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int n=s.length();
        if(n<4 || n>12) return {};
        string ip;
        vector<string> result;
        recursion(s,0,n,result,ip,0);
        return result;
    }
};

// My implementation
class Solution2 {
    bool isValid(const string &seg){
        if(seg.size()==0) return false;
        if(seg[0]=='0' && seg.size()>1) return false;
        int segNum=stoi(seg);
        return segNum<=255;
    }

    void recursion(string &s,int i,int n,vector<string> &result,string ip,int dotCount){
        if(i==n && dotCount==3){
            result.push_back(ip);
            return ;
        }
        if(i==n || dotCount>=3) return ;

        if(!ip.empty()){
            ip.push_back('.');
            dotCount++;
        }
        
        for(int j=i;j<min(i+3,n);j++){
            string temp=s.substr(i,j-i+1);
            if(!isValid(temp)) return ;
            ip+=temp;
            recursion(s,j+1,n,result,ip,dotCount);
            for(int k=0;k<j-i+1;k++)
                ip.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        int n=s.length();
        recursion(s,0,n,result,ip,0);
        return result;
    }
};

void print(vector<string> IPs){
    for(string &ip:IPs)
        cout<<ip<<"  ";
    cout<<endl;
}

int main(){
    Solution1 s;
    print(s.restoreIpAddresses("190345"));
return 0;
}