#include <bits/stdc++.h>
using namespace std;

int solve(int n,vector<string> &players){
    vector<bool> parityOfWeapons(10,0);
    for(auto &player: players){
        for(int i=0;i<10;i++){
            if(player[i]=='1') 
                parityOfWeapons[i]=1^parityOfWeapons[i];
        }
    }
    int count=0;
    for(int i=0;i<10;i++){
        count=count+parityOfWeapons[i];
    }
    return count;
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<string> players(n);
        for(int j=0;j<n;j++){
            cin>>players[j];
        }
        cout<<solve(n,players)<<endl;
    }
    return 0;
}
