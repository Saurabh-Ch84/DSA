#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n==2) cout<<"10"<<endl;
        else{
            string binaryString(n, '0');
            binaryString[0] = '1';
            binaryString[n-1] = '1';
            cout << binaryString << endl;
        }
    }
    return 0;
}