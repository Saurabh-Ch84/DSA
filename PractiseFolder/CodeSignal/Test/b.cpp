#include <iostream>
#include <vector>

using namespace std;

/*
    PROBLEM: Array Reduction Algorithm (Question 2)
    
    You are given an array of non-negative integers 'numbers'. Perform the following algorithm:

    Step 1: Find the index 'i' of the leftmost non-zero element. 
            Let x = numbers[i]. 
            If no such element exists (all zeros), finish the algorithm.
    
    Step 2: Starting at index 'i' and going to the right, attempt to subtract 'x' from each element.
            - If the current element is strictly less than 'x', STOP this step and move to Step 3.
            - Otherwise, subtract 'x' from the element and move to the next element.
            - If you reach the end of the array, move to Step 3.
    
    Step 3: Add 'x' to the final result.
    
    Step 4: Go back to Step 1.

    Returns the resulting sum obtained from Step 3.

    CONSTRAINTS:
    - 1 <= numbers.length <= 100
    - 0 <= numbers[i] <= 10^6
    - Execution time: 0.5s
*/

int solution(vector<int> numbers) {
    int result=0,n=numbers.size();
    int left=0;
    while(left<n){
        if(numbers[left]){
            int mini=numbers[left];
            int right=left;
            while(right<n && numbers[right]>=mini){
                numbers[right]-=mini;
                right++;
            }   
            result+=mini;
        }
        left++;
    }
    return result;
}

int main() {
    // --- Test Case 1 ---
    // Explanation:
    // 1. x=3 (at idx 0). Subtract 3 from [3, 3, 5]. Stops at 2. Array: [0, 0, 2, 2, 3]. Result += 3.
    // 2. x=2 (at idx 2). Subtract 2 from [2, 2, 3]. Array: [0, 0, 0, 0, 1]. Result += 2.
    // 3. x=1 (at idx 4). Subtract 1 from [1]. Array: [0, 0, 0, 0, 0]. Result += 1.
    // Total = 6.
    vector<int> t1 = {3, 3, 5, 2, 3};
    cout << "Test Case 1: " << solution(t1) << " (Expected: 6)" << endl;

    // --- Test Case 2 ---
    // Explanation: 
    // 1. x=5 (at idx 0). Subtract 5 from all. Array: [0, 0, 0, 0]. Result += 5.
    // Stops immediately.
    vector<int> t2 = {5, 5, 5, 5};
    cout << "Test Case 2: " << solution(t2) << " (Expected: 5)" << endl;

    // --- Test Case 3 ---
    // Already empty/zeros. Should return 0.
    vector<int> t3 = {0, 0, 0};
    cout << "Test Case 3: " << solution(t3) << " (Expected: 0)" << endl;

    return 0;
}