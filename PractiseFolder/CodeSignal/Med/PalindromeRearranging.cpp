#include<iostream>
#include<vector>
using namespace std;

/*
**Given a string, find out if its characters can be rearranged to form a palindrome.**

#### Example

For  
```  
inputString = "aabb"  
```  
the output should be  
```  
palindromeRearranging(inputString) = true  
```  
We can rearrange `"aabb"` to make `"abba"`, which is a palindrome.

---

### Input/Output

- **[execution time limit]** 4 seconds (js)

- **[input] string inputString**  
  A string consisting of lowercase English letters.  
  Guaranteed constraints:  
  \(1 \leq \text{inputString.length} \leq 50\)

- **[output] boolean**  
  `true` if the characters of the `inputString` can be rearranged to form a palindrome, `false` otherwise.
*/

bool palindromeRearranging(string str){
    vector<int> freqArr(26,0);
    for(char ch: str){
        int idx=ch-'a';
        freqArr[idx]++;
    }

    bool flag=false;
    for(int freq: freqArr){
        if(freq & 1){
            if(flag) return false;
            flag=true;
        }
    }
    return true;
}

int main(){
    cout<<palindromeRearranging("aabb")<<endl;
    cout<<palindromeRearranging("saurabh")<<endl;
    cout<<palindromeRearranging("monom")<<endl;
    cout<<palindromeRearranging("vivi")<<endl;
    cout<<palindromeRearranging("popo")<<endl;
return 0;
}