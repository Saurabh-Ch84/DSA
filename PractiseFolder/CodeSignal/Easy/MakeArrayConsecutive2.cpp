#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
**makeArrayConsecutive2**

Ratiorg got statues of different sizes as a present from CodeMaster for his birthday, 
each statue having a non-negative integer size. Since he likes to make things perfect, 
he wants to arrange them from smallest to largest so that each statue will be bigger 
than the previous one exactly by 1. He may need some additional statues to be able to 
accomplish that. 

Help him figure out the minimum number of additional statues needed.

**Example:**  
For `statues = [6, 2, 3, 8]`, the output should be `makeArrayConsecutive2(statues) = 3`.  
Ratiorg needs statues of sizes 4, 5 and 7.

**Input/Output**  
- [execution time limit] 4 seconds (py3)  
- [input] array.integer statues  
  An array of distinct non-negative integers.  
  Guaranteed constraints: `1 ≤ statues.length ≤ 10`,  
  `0 ≤ statues[i] ≤ 20`.

- [output] integer
*/

class Solution{
    public:
  int additionalStatues(vector<int> nums){
    int count=0,n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-1;i++){
      int diff=nums[i+1]-nums[i];
      if(diff>1) count+=diff-1;
    }
    return count;
  }
};

int main(){
  Solution s;
  cout<<s.additionalStatues({6,2,3,8})<<endl;
return 0;
}