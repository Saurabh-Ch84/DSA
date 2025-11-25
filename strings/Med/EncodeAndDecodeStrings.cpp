#include<iostream>
#include<vector>
using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        // Your code here
        string encoded;
        for(string &str: strs){
            int n=str.length();
            encoded=encoded+to_string(n)+'#'+str+'#';
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        // Your code here
        int idx=0,n=s.length();
        vector<string> decoded;
        while(idx<n){
            int sz=0,i=idx;
            while(isdigit(s[i])){
                sz=sz*10+1LL*(s[i]-'0');
                i++;
            }
            string str=s.substr(i+1,sz);
            decoded.push_back(str);
            idx=i+sz+2;
        }
        return decoded;
    }
};

bool verify(vector<string> &a,vector<string> &b){
    int n=a.size();
    if(n!=b.size()) 
        return false;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

int main(){
    Codec cd;
    vector<string> a={"I1","Love_","_",""};
    string coded=cd.encode(a);
    vector<string> b=cd.decode(coded);
    if(verify(a,b)) cout<<"It Works!";
    else cout<<"Go To Hell!";
return 0;
}