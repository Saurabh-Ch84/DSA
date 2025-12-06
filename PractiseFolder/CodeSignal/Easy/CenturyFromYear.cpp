#include<iostream>
using namespace std;

/*
**Easy Codewriting**  
**300**

**Century From Year**

**Given a year, return the century it is in.**  
The first century spans from the year 1 up to and including the year 100,  
the second – from the year 101 up to and including the year 200, etc.

**Example:**  
- For `year = 1905`, the output should be `centuryFromYear(year) = 20`;  
- For `year = 1700`, the output should be `centuryFromYear(year) = 17`.

**Input/Output**  
- [execution time limit] 4 seconds (py3)  
- [input] integer year  
  A positive integer, designating the year.  
  Guaranteed constraints: `1 ≤ year ≤ 2005`.

---

*/

class Solution{
        public:
    int getCentury(int n){
        int century=(n+100-1)/100;
        return century;
    }
};

int main(){
    Solution s;
    cout<<s.getCentury(1905)<<endl;
    cout<<s.getCentury(1700)<<endl;
return 0;
}