#include<iostream>
using namespace std;

/*
    Q2. Given a number find all its prime factorization and then evaluate 
    the number according to a given array.

    TC-1  Input: n=25, arr=[1, 2, 3, 2, 5, 6] 
        Output: As prime factorization of 25 is 5*5.
*/

class Solution{
        public:
    int q2(int arr[],int n){
        int sum=0,exp=0;
        while(n%2==0){
            n=n/2;
            exp++;
        }
        if(exp) sum+=exp*arr[2];
        exp=0;

        for(int i=3;i*i<=n;i+=2){
            while(n%i==0){
                exp++;
                n=n/i;
            }
            if(exp){
                sum+=exp*arr[i];
                exp=0;
            }
        }

        if(n > 2) sum += 1 * arr[n];
        return sum;
    }
};

int main(){
    int arr[]={1,3,2,7,4,6};
    Solution s;
    cout<<s.q2(arr,30);
return 0;
}