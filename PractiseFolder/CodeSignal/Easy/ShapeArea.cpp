#include<iostream>
using namespace std;

/*

**n-Interesting Polygon**

Below we will define an n-interesting polygon. Your task is to find the area of a polygon for a given `n`.

A **1-interesting polygon** is just a square with a side of length 1.  
An **n-interesting polygon** is obtained by taking the `n - 1`-interesting polygon 
and appending 1-interesting polygons to its rim, side by side.

You can see the 1-, 2-, 3-, and 4-interesting polygons in the picture below.

**Example**
- For `n = 2`, the output should be  
  `solution(n) = 5`
- For `n = 3`, the output should be  
  `solution(n) = 13`

**Input/Output**
- **[execution time limit]** 4 seconds (py3)
- **[memory limit]** 1 GB
- **[input] integer n**

*/

class Solution{
        public:
    int areaDP(int n){
        if(!n) return 0;
        int a=1,b=0,k=1;
        while(k<=n){
            b=a+(k-1)*4;
            a=b;
            k++;
        }
        return b;
    }

    int areaMath(int n){
        return n*n + (n-1)*(n-1);
    }
};

int main(){
    Solution s;
    cout<<s.areaMath(0)<<endl;
    cout<<s.areaMath(1)<<endl;
    cout<<s.areaMath(2)<<endl;
    cout<<s.areaMath(3)<<endl;
    cout<<s.areaMath(4)<<endl;
return 0;
}