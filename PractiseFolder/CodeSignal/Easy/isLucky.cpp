#include<iostream>
using namespace std;

/*

**Is Lucky**

Ticket numbers usually consist of an even number of digits. 
A ticket number is considered lucky if the sum of the first half 
of the digits is equal to the sum of the second half.

**Given a ticket number `n`, determine if it's lucky or not.**

**Example**  
- For `n = 1230`, the output should be `isLucky(n) = true`;  
- For `n = 239017`, the output should be `isLucky(n) = false`.

**Input/Output**

- **[execution time limit]** 4 seconds (py3)

- **[input] integer n**  
  A ticket number represented as a positive integer with an even number of digits.  
  *Guaranteed constraints:*  
  `10 ≤ n < 10⁶`

- **[output] boolean**  
  `true` if `n` is a lucky ticket number, `false` otherwise.

*/

class Solution{
        public:
    bool isLucky(int num){
        string number=to_string(num);
        int n=number.length();
        int leftSum=0,rightSum=0;
        int left=0,right=n-1;
        while(left<right){
            rightSum+=number[right]-'0';
            leftSum+=number[left]-'0';
            left++;
            right--;
        }
        return leftSum==rightSum;
    }
};  

int main(){
    Solution s;
    cout<<s.isLucky(1230)<<endl;
    cout<<s.isLucky(239017)<<endl;
return 0;
}