#include<iostream>
#include<vector>
using namespace std;

/*

### Problem Statement

**Given a rectangular matrix of characters, add a border of asterisks (*) to it.**

#### Example

For  
```  
picture = ["abc",  
           "ded"]  
```  
the output should be  
```  
addBorder(picture) = ["*****",  
                      "*abc*",  
                      "*ded*",  
                      "*****"]  
```

---

### Input/Output

- **[execution time limit]** 4 seconds (js)
- **[input] array.string picture**  
  A non-empty array of non-empty equal-length strings.
*/
class Solution{
        public:
    vector<vector<char>> addBorder(vector<vector<char>> matrix){
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<char>> result(n+2,vector<char>(m+2,'*'));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch=matrix[i][j];
                result[i+1][j+1]=ch;
            }
        }
        return result;
    }

    void print(vector<vector<char>> matrix){
        for(vector<char> v: matrix){
            for(char ch: v)
                cout<<ch<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
};

int main(){
    Solution s;
    vector<vector<char>> matrix={{'a','b','c'},{'d','e','f'}};
    s.print(matrix);
    s.print(s.addBorder(matrix));
return 0;
}