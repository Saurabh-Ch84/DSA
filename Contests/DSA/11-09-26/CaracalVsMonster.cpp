#include<bits/stdc++.h>
using namespace std;

long long recursion(long long H){
    if(H <= 1) return 1;
    return recursion(H / 2) * 2 + 1;
}

long long solve(long long H){
    return recursion(H);
}

int main(){
    long long H;
    cin >> H;
    cout << solve(H);
    return 0;
}