#include<iostream>
#include<vector>
using namespace std;

/*
### Problem Statement

**Given an array of integers, find the maximal absolute difference between any two of its adjacent elements.**

#### Example

For  
```  
inputArray = [2, 4, 1, 0]  
```  
the output should be  
```  
arrayMaximalAdjacentDifference(inputArray) = 3  
```

---

### Input/Output

- **[execution time limit]** 4 seconds (js)

- **[input] array.integer inputArray**  
  Guaranteed constraints:  
  \(3 \leq \text{inputArray.length} \leq 10\)  
  \(-15 \leq \text{inputArray[i]} \leq 15\)

- **[output] integer**  
  The maximal absolute difference.
*/

int arrayMaximalAdjacentDifference(vector<int> nums){
    int n=nums.size();
    int maxi=0;
    for(int i=0;i<n-1;i++){
        maxi=max(maxi,abs(nums[i]-nums[i+1]));
    }
    return maxi;
}

int main(){
    cout<<arrayMaximalAdjacentDifference({2,4,1,0})<<endl;
return 0;   
}