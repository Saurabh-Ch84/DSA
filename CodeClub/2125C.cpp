#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*

A prime number is a positive integer that has exactly two divisors: 1 and itself. 
The first several prime numbers are 2,3,5,7,11,…
.
Prime factorization of a positive integer is representing it as a product of prime numbers. For example:
the prime factorization of 111 is 3⋅37;
the prime factorization of 43 is 43.
the prime factorization of 12 is 2⋅2⋅3.
For every positive integer, its prime factorization is unique (if you don't consider the order of primes in the product).

We call a positive integer good if all primes in its factorization consist of at least two digits. For example:

343=7⋅7⋅7 is not good;
111=3⋅37 is not good;
1111=11⋅101 is good;
43=43 is good.
You have to calculate the number of good integers from l to r (endpoints included).

Input
The first line contains one integer t (1≤t≤103) — the number of test cases.

Each test case consists of one line containing two integers l and r (2≤l≤r≤1018).

Output
For each test case, print one integer — the number of good integers from l to r.

Example

Input
4
2 100
2 1000
13 37
2 1000000000000000000

Output
21
227
7
228571428571428570

*/

int main(){
    int t;
    cin>>t;
    while(t){
        long long l,r;
        cin>>l>>r;
        long long total=r-l+1; // Total numbers in the range
        
        long long bad_count=0; // Count of bad numbers
        
        // Sum of counts of multiples of single primes
        bad_count += (r/2) - ((l-1)/2);
        bad_count += (r/3) - ((l-1)/3);
        bad_count += (r/5) - ((l-1)/5);
        bad_count += (r/7) - ((l-1)/7);
        
        // Subtract sum of counts of multiples of pairs
        bad_count -= (r/6) - ((l-1)/6);
        bad_count -= (r/10) - ((l-1)/10);
        bad_count -= (r/14) - ((l-1)/14);
        bad_count -= (r/15) - ((l-1)/15);
        bad_count -= (r/21) - ((l-1)/21);
        bad_count -= (r/35) - ((l-1)/35);
        
        // Add back sum of counts of multiples of triplets
        bad_count += (r/30) - ((l-1)/30);
        bad_count += (r/42) - ((l-1)/42);
        bad_count += (r/70) - ((l-1)/70);
        bad_count += (r/105) - ((l-1)/105);
        
        // Subtract count of multiples of all four primes
        bad_count -= (r/210) - ((l-1)/210);
        
        long long good_count = total - bad_count;
        cout << good_count << endl;
        t--;
    }
    return 0;
}