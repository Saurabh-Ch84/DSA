#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    for (int divisor : divisors) cout << divisor << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
    } else {
        cout << "Divisors of " << n << " are: ";
        printDivisors(n);
    }
    
    return 0;
}