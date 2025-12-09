#include<iostream>
#include<vector>
using namespace std;

/*
**You are given an array of integers. On each move you are allowed to increase exactly one of its elements by one.
 Find the minimal number of moves required to obtain a strictly increasing sequence from the input.**

#### Example

For  
```  
inputArray = [1, 1, 1]  
```  
the output should be  
```  
arrayChange(inputArray) = 3  
```

---

### Input/Output

- **[execution time limit]** 4 seconds (js)

- **[input] array.integer inputArray**  
  Guaranteed constraints:  
  \(3 \leq \text{inputArray.length} \leq 10^5\)  
  \(-10^5 \leq \text{inputArray[i]} \leq 10^5\)

- **[output] integer**  
  The minimal number of moves needed to obtain a strictly increasing sequence from `inputArray`.  
  It’s guaranteed that for the given test cases the answer always fits signed 32-bit integer type.
*/

int arrayChange(vector<int> nums){
    if(nums.empty()) return 0;
    int n=nums.size();
    int count=0,prev=nums[0];
    for(int i=1;i<n;i++){
        int curr=nums[i];
        if(curr<=prev){
            int temp=prev-curr+1;
            count+=temp;
            curr+=temp;
        }
        prev=curr;
    }
    return count;
}

int main(){
    cout<<arrayChange({1,1,1})<<endl;
return 0;
}