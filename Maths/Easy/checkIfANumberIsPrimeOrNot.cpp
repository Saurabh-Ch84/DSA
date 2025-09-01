#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    // 1 and numbers less than or equal to 1 are not prime
    if (n == 2) return true;
    if (n <= 1 || n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    
    if (isPrime(num)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }
    
    return 0;
}