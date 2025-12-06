#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
**All Longest Strings**

**Given an array of strings, return another array containing all of its longest strings.**

**Example**  
For `inputArray = ["aba", "aa", "ad", "vcd", "aba"]`,  
the output should be  
`allLongestStrings(inputArray) = ["aba", "vcd", "aba"]`.

**Input/Output**

- **[execution time limit]** 4 seconds (py3)

- **[input] array.string inputArray**  
  A non-empty array.  
  *Guaranteed constraints:*  
  ```
  1 ≤ inputArray.length ≤ 10  
  1 ≤ inputArray[i].length ≤ 10
  ```

- **[output] array.string**  
  Array of the longest strings, stored in the same order as in the `inputArray`.
*/

class Solution{
    struct Comp{
        bool operator()(const string &a,const string &b) const{
            int A=a.length();
            int B=b.length();
            if(A!=B) return A>B;
            return a<b;
        }
    };
        public:
    vector<string> allLongestStrings1(vector<string> words){
        vector<string> result;
        int n=words.size();
        sort(words.begin(),words.end(),Comp());
        int len=words[0].length(),ptr=0;
        while(ptr<n && words[ptr].length()==len){
            result.push_back(words[ptr]);
            ptr++;
        }
        return result;
    }

    vector<string> allLongestStrings2(vector<string> words){
        vector<string> result;
        int n=words.size(),maxLen=0;
        for(int i=0;i<n;i++){
            int len=words[i].length();
            maxLen=max(maxLen,len);
        }
        for(int i=0;i<n;i++){
            if(words[i].length()==maxLen){
                result.push_back(words[i]);
            }
        }
        return result;
    }

    void print(vector<string> words){
        for(string &word: words)
            cout<<word<<" ";
        cout<<endl;
    }
};

int main(){
    vector<string> inputArray = {"aba", "aa", "ad", "vcd", "aba"};
    Solution s;
    s.print(inputArray);
    s.print(s.allLongestStrings2(inputArray));
return 0;
}