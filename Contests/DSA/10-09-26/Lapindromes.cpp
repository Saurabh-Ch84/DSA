#include<bits/stdc++.h>
using namespace std;

string solve(string &str){
    vector<int> letters(26,0);
    int n=str.size();
    for(int i=0;i<n/2;i++){
        int idx=str[i]-'a';
        letters[idx]++;
    }
    for(int i=n/2;i<n;i++){
        if(i==n/2 && n%2==1) continue;
        int idx=str[i]-'a';
        letters[idx]--;
    }
    for(int i=0;i<26;i++){
        if(letters[i]) return "NO";
    }
    return "YES";
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str;
        cin>>str;
        cout<<solve(str)<<endl;
    }
return 0;
}