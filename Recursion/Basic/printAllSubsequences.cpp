#include<iostream>
#include<vector>
using namespace std;

void recursion(string &s,int i,int n,string &temp){
    if(i>=n)
    {
        cout<<temp<<"_";
        return;
    }
    temp.push_back(s[i]);
    recursion(s,i+1,n,temp);
    temp.pop_back();
    recursion(s,i+1,n,temp);
}

int main(){
    string s;
    cout<<"Enter s:";
    cin>>s;
    string temp="";
    recursion(s,0,s.size(),temp);
return 0;
}