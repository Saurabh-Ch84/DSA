#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    Given an integer N, find how many locks are open after N passes of toggling.
*/

int countOpenLocks1(int N) {
    // Initialize all locks to closed (false)
    vector<bool> locks(N, false);
    // Outer loop for each pass
    for (int i = 1; i <= N; ++i) {
        // Inner loop to toggle locks that are multiples of the current pass number
        for (int j = i - 1; j < N; j += i) {
            locks[j] = !locks[j];
        }
    }
    // Count the number of open locks (true)
    int openCount = 0;
    for (bool lock : locks) {
        if (lock) {
            openCount++;
        }
    }
    return openCount;
}

int countOpenLocks2(int N){
    return sqrt(N);
}

int main(){
    int n;
    cout<<"Enter the number of locks: ";
    cin>>n;
    cout<<countOpenLocks2(n);
return 0;
}