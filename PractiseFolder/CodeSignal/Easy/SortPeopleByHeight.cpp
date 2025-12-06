#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
**Sort by Height**

Some people are standing in a row in a park. There are trees between them which 
cannot be moved. Your task is to rearrange the people by their heights in a non-descending 
order without moving the trees. People can be very tall!

**Example**  
For `a = [-1, 150, 190, 170, -1, -1, 160, 180]`,  
the output should be  
`sortByHeight(a) = [-1, 150, 160, 170, -1, -1, 180, 190]`.

**Input/Output**

- **[execution time limit]** 4 seconds (py3)

- **[input] array.integer a**  
  If `a[i] = -1`, then the ith position is occupied by a tree.  
  Otherwise `a[i]` is the height of a person standing in the ith position.  
  *Guaranteed constraints:*  
  ```
  1 ≤ a.length ≤ 1000  
  -1 ≤ a[i] ≤ 1000
  ```

- **[output] array.integer**  
  The array with people sorted by height, trees left untouched.
*/


class Solution{
        public:
    vector<int> sortByHeight(vector<int> nums){
        vector<int> arr;
        for(int &num: nums){
            if(num!=-1){
                arr.push_back(num);
            }
        }
        sort(arr.rbegin(),arr.rend());
        for(int &num: nums){
            if(num==-1) continue;
            num=arr.back();
            arr.pop_back();
        }
        return nums;
    }

    void print(vector<int> nums){
        for(int &num: nums)
            cout<<num<<" ";
        cout<<endl;
    }
};


int main(){
    vector<int> a = {-1, 150, 190, 170, -1, -1, 160, 180};
    Solution s;
    s.print(a);
    s.print(s.sortByHeight(a));
return 0;
}