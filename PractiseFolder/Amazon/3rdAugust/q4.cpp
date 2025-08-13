#include<iostream>
using namespace std;

/*Explanation of the logic:
When n is even (n % 2 == 0):
Dividing by 2 is always optimal because dividing halves the number, quickly reducing it.
Example:
8 → 4 → 2 → 1

When n is odd:
You must decide whether to do n + 1 or n - 1 to get closer to 1 in fewer steps. This decision is the core of the logic.

The code uses two checks to guide this:

Special case: n == 3
For 3, subtracting 1 is optimal:
3 → 2 → 1 (2 steps), compared to 3 → 4 → 2 → 1 (3 steps if adding 1).
So if n == 3, do n - 1.

Check (n % 4 == 1) → n - 1
If the last two bits (bitmask) of n are 01, it's better to subtract 1 and then do division.
Explanation: numbers ending with bit pattern 01 (like 5, 9, 13...)
Subtracting 1 converts n to a multiple of 4, which can be halved repeatedly after that, reducing steps.

Else (bitmask 11) → n + 1
If the number ends with bit pattern 11 — i.e., n % 4 == 3 (like 7, 11, 15...) — it's better to add 1 to reach a multiple of 4.
This again facilitates multiple divisions by 2 on the next steps.*/

class Solution{
    int recursion(int num){
        //highly inefficient
        if(num<1) return 1e6;
        if(num==1) return 0;
        if(num%2==0) return 1+recursion(num/2);
        return 1+min(recursion(num-1),recursion(num+1));
    }
    int magicFun(int num){
        int count=0;
        while(num>1){
            count++;
            if(num%2==0) num=num/2;
            else if(num % 4 == 1 || num == 3) num-=1;
            else num+=1;
        }
        return count;
    }
        public:
    int minCalc(int num){
        // return recursion(num);
        return magicFun(num);
    }
};

int main(){
    Solution s;
    int num=15;
    cout<<s.minCalc(num)<<endl;
return 0;
}