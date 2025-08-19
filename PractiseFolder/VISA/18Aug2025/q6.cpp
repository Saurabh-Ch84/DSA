#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    Given an integer N, find how many locks are open after N passes of toggling.
*/

int countOpenLocks(int N){
    return sqrt(N);
}

int main(){
    int n;
    cout<<"Enter the number of locks: ";
    cin>>n;
    cout<<countOpenLocks(n);
return 0;
}