#include<iostream>
#include<vector>
using namespace std;

/*
**Common Character Count**

**Given two strings, find the number of common characters between them.**

**Example**  
For `s1 = "aabcc"` and `s2 = "adcaa"`,  
the output should be  
`commonCharacterCount(s1, s2) = 3`.

Strings have 3 common characters — 2 `"a"`s and 1 `"c"`.

**Input/Output**

- **[execution time limit]** 4 seconds (py3)

- **[input] string s1**  
  A string consisting of lowercase English letters.  
  *Guaranteed constraints:*  
  `1 ≤ s1.length < 15`

- **[input] string s2**  
  A string consisting of lowercase English letters.  
  *Guaranteed constraints:*  
  `1 ≤ s2.length < 15`

- **[output] integer**

*/

class Solution{
        public:
    int commonCharCount(string s1,string s2){
        int count=0;
        vector<int> freqArr(26,0);
        for(char ch: s1){
            int idx=ch-'a';
            freqArr[idx]++;
        }
        for(char ch: s2){
            int idx=ch-'a';
            if(freqArr[idx]){
                freqArr[idx]--;
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    cout<<s.commonCharCount("aabcc","adcaa");
return 0;
}