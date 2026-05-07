#include <bits/stdc++.h>
using namespace std;

int findMinAmount(int n,int m,int a,int b,int c){
    int k=min(n,m);
    int cost=c*k+(k==n? (m-k)*b: (n-k)*a);
    return cost;
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m,a,b,c;
        cin>>n>>m>>a>>b>>c;
        cout<<findMinAmount(n,m,a,b,c)<<endl;
    }
}
