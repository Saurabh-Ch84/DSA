#include<iostream>
#include<vector>

using namespace std;
using vi = vector<int> ;

// You probably know about the famous Fibonacci sequence, which involves generating terms by adding up
// the previous two terms. But did you know that the concept can be extended to the general n-bonacci numbers,
// where each term is the sum of the previous n terms?
// For example, [1, 1, 1, 3, 5, 9, 17, 31] is a 3-bonacci sequence, since each term is the sum of the
// previous 3 terms(except for the first 3 terms).
// PROBLEM: Given a sequence of numbers(in the form of an array of integers), your task is to find
//          the "degree" of the n-bonacci sequence(in other words, find the value of n).
//          If the sequence does not form an n-bonacci sequence, return -1.
// Example:
//          For sequence = [1, 2, 3], the output should be nbonacciDegree(sequence) = 2.
//          It's not a very long sequence, but since 1 + 2 = 3, it qualifies as a 2-bonacci sequence,
//          so the answer is 2.
//
//          For sequence = [0, 6, -2, 3, 7, 14, 22, 46, 89, 171, 328, 634, 1222, 2355],
//          the output should be nbonacciDegree(sequence) = 4.
//          After the first four terms, each term of the sequence is the sum of the previous 4 terms,
//          so the answer is 4.
//
//          For sequence = [1, 2, 5], the output should be nbonacciDegree(sequence) = -1.
//          This sequence does not qualify as n-bonacci, since none of the terms are sums
//          of any number of previous terms.

int nbonacciDegree(vi &sequence){
    int len=sequence.size();
    long long currWindowSum=0;
    for(int n=1;n<len;n++){
        currWindowSum+=sequence[n-1];
        long long windowSum=currWindowSum;
        bool flag=true;
        for(int i=n;i<len;i++){
            if(windowSum!=sequence[i]){
                flag=false;
                break;
            }
            windowSum-=sequence[i-n];
            windowSum+=sequence[i];
        }
        if(flag) return n;
    }
    return -1;
}


int main(){
    // Test
    vector<int> seq = {0, 6, -2, 3, 7, 14, 22}; 
    cout << "Degree: " << nbonacciDegree(seq) << endl; // Output: 4
    return 0;
return 0;
}