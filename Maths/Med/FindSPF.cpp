#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 1e6;
vector<int> spf(MAXN+1);

void sieve() {
    for (int i = 1; i < MAXN; i++) spf[i] = i;

    for (int i = 4; i < MAXN; i += 2)
        if (spf[i] == i) spf[i] = 2;

    for (int p = 3; p * p < MAXN; p += 2) {
        if (spf[p] == p){
            for (int i = p * p; i < MAXN; i += p) {
                if (spf[i] == i) spf[i] = p;
            }
        }
    }
}

void getPrimeFactorization(int n) {
    while (n != 1) {
        cout << spf[n] << " ";
        n = n / spf[n];
    }
    cout << endl;
}

int main() {
    sieve();

    cout << "Smallest prime factor of 12 is: " << spf[12] << endl; 
    cout << "Smallest prime factor of 25 is: " << spf[25] << endl; 
    cout << "Smallest prime factor of 30 is: " << spf[30] << endl; 
    
    cout << "\nPrime factorization of 12: ";
    getPrimeFactorization(12);

    return 0;
}