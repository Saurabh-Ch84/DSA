#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
**Adjacent Elements Product**

**Given an array of integers, find the pair of adjacent elements that has the largest product and 
    return that product.**

**Example:**  
For `inputArray = [3, 6, -2, -5, 7, 3]`,  
the output should be `adjacentElementsProduct(inputArray) = 21`.  

7 and 3 produce the largest product.

**Input/Output**  
- [execution time limit] 4 seconds (py3)  
- [input] array.integer inputArray  
  An array of integers containing at least two elements.

*/

class Solution{
        public:
    int maxProduct(vector<int> nums){
        int maxi=INT_MIN,n=nums.size();
        int left=0,right=1;
        while(right<n){
            int product=nums[left]*nums[right];
            maxi=max(maxi,product);
            left=right;
            right++;
        }
        return maxi;
    }
};

int main(){
    Solution s;
    cout<<s.maxProduct({3,6,-2,-5,7,3})<<endl;
return 0;
}