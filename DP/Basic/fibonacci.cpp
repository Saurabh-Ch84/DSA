#include<iostream>
#include<vector>
using namespace std;

// Dynamic Programming lecture-1: Fibonacci Sequence

// Method 1: Simple Recursive (Inefficient)
int fib1(int n)
{
    cout<<"A"; // Prints 'A' to count recursive calls
    if(n<=1)
        return n; // Base case: fib(0) = 0, fib(1) = 1
    return fib1(n-2) + fib1(n-1); // Recursive case: fib(n) = fib(n-2) + fib(n-1)
}

// Method 2: Memoization (Top-down DP)
int fib2(int n, vector<int>& v)
{
    cout<<"B"; // Prints 'B' to count memoization calls
    if(n<=1){
        v[n] = n; // Store base cases in memoization array
        return n;
    }
    if(v[n] == -1) // If value not memoized yet
    {
        v[n] = fib2(n-2,v) + fib2(n-1,v); // Calculate and store in memoization array
    }
    return v[n]; // Return memoized value
}

// Method 3: Tabulation (Bottom-up DP)
int fib3(int n, vector<int> &v)
{
    if(n<=1)
        return n; // Handle base cases
    v[0] = 0, v[1] = 1; // Initialize base cases
    for(int i=2; i<=n; i++)
    {
        cout<<"C"; // Prints 'C' to count iterations
        v[i] = v[i-2] + v[i-1]; // Fill the table iteratively
    }
    return v[n]; // Return the final result
}

int fib4(int n){
    int a=0,b=1;
    if(n<0) return -1;
    if(n<2) return n;
    int temp=0;
    while(n>1){
        cout<<"D";
        temp=a;
        a=b;
        b=temp+a;
        n--;
    }   
    return b;
}

int main(){
    int n;
    cout<<"N:";
    cin>>n;
    vector<int> v1(n+1, -1); // Memoization array initialized with -1
    vector<int> v2(n+1);     // Tabulation array

    // Calculate Fibonacci number using all four methods
    cout << fib1(n) << endl;    // Simple recursion (least efficient)
    cout << fib2(n,v1) << endl; // Memoization
    cout << fib3(n,v2) << endl; // Tabulation (most efficient)
    cout<<fib4(n)<<endl;//Tabulation (with space optimisation)
    return 0;
}
