#include<iostream>
using namespace std;

/*
### Problem Statement

**Each character in the given string must be replaced by the next character in the English alphabet.**  
- For example: `'a'` becomes `'b'`, `'b'` becomes `'c'`, and `'z'` wraps around to become `'a'`.

---

### Example

For  
```
inputString = "crazy"
```
the output should be  
```
alphabeticShift(inputString) = "dsbaz"
```

---

### Input/Output

- **[execution time limit]** 4 seconds (js)

- **[input] string inputString**  
  A non-empty string consisting of lowercase English characters.

- **Guaranteed constraints:**  
  \( 1 \leq \text{inputString.length} \leq 1000 \)

- **[output] string**  
  The resulting string after replacing each of its characters.

*/
string alphabeticShift(string str){
    int n=str.length();
    for(int i=0;i<n;i++){
        str[i]=(str[i]-(int)'a'+1) % 26+'a';
    }
    return str;
}

int main(){
    cout<<alphabeticShift("crazy")<<endl;
    cout<<alphabeticShift("saurabh")<<endl;
    cout<<alphabeticShift("hello")<<endl;
return 0;
}