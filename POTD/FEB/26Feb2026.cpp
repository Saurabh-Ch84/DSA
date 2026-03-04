#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    void divide2(string &s){
        s.pop_back();
    }
    void add1(string &s){
        reverse(s.begin(),s.end());
        int n=s.length(), i=0, carry=1;
        while(carry){
            int val=(i<n? s[i]-'0':0);
            int bit=val^carry;
            carry=carry&val;
            if(i<n) s[i]=bit+'0';
            else s.push_back(bit+'0');
            i++;
        }   
        reverse(s.begin(),s.end());
    }
public:
    int numSteps(string s) {
        int count=0;
        while(s!="1"){
            if(s.back()=='1') add1(s);
            else divide2(s);
            count++;
        }
        return count;
    }
};

class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        int n=s2.length();
        vector<int> alphabetsU(26,-1);
        vector<int> alphabetsV(26,-1);
        for(int i=0;i<n;i++){
            int u=s1[i]-'a';
            int v=s2[i]-'a';
            if(alphabetsU[u]!=-1 && alphabetsU[u]!=v)
                return false;
            if(alphabetsV[v]!=-1 && alphabetsV[v]!=u)
                return false;
            alphabetsU[u]=v;
            alphabetsV[v]=u;
        }
        return true;
    }
};

int main(){

return 0;
}