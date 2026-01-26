#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_R = 1000000; // Define a reasonable upper limit for R

vector<bool> isPrime(MAX_R + 1, true);
vector<int> prefixPrimes(MAX_R + 1, 0);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p<= MAX_R; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= MAX_R; i += p)
                isPrime[i] = false;
        }
    }

    for (int i = 1; i <= MAX_R; i++) {
        prefixPrimes[i] = prefixPrimes[i - 1];
        if (isPrime[i]){
            prefixPrimes[i]++;
        }
    }
}

int countPrimesInRange(int L, int R) {
    if (L > R) return 0;
    int countR = prefixPrimes[R];
    int countL_minus_1 = (L > 0) ? prefixPrimes[L - 1] : 0;
    return countR - countL_minus_1;
}

int main() {
    sieve();
    int L, R;
    cout << "Enter the range [L, R]: ";
    cin >> L >> R;
    int primeCount = countPrimesInRange(L, R);
    cout << "Number of primes between " << L << " and " << R << " is: " << primeCount << endl;
    return 0;
}