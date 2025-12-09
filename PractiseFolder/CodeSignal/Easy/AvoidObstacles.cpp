#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
### Problem Statement

**You are given an array of integers representing coordinates of obstacles situated on a straight line.**

Assume that you are jumping from the point with coordinate 0 to the right. You are allowed only to make jumps of the same length represented by some integer.

**Find the minimal length of the jump enough to avoid all the obstacles.**

---

### Example

For  
```  
inputArray = [5, 3, 6, 7, 9]  
```  
the output should be  
```  
avoidObstacles(inputArray) = 4  
```

---

### Input/Output

- **[execution time limit]** 4 seconds (js)

- **[input] array.integer inputArray**  
  Non-empty array of positive integers.

- **[output] integer**  
  The minimal jump length needed to avoid all obstacles.
*/
class Solution {
    bool isValidJump(const unordered_set<int> &obstacles, int jump, int maxObs) {
        for(int pos = 0; pos <= maxObs; pos += jump) {
            if(obstacles.count(pos)) return false;
        }
        return true;
    }
public:
    int avoidObstacles(vector<int> nums) {
        unordered_set<int> obstacles(nums.begin(), nums.end());
        int maxObs = *max_element(nums.begin(), nums.end());
        for(int jump = 2; jump <= maxObs + 1; jump++) {
            if(isValidJump(obstacles, jump, maxObs)) return jump;
        }
        return maxObs + 1; // fallback
    }
};

int main(){
    Solution s;
    cout<<s.avoidObstacles({5,3,6,7,9})<<endl;
return 0;
}