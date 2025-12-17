#include <iostream>
#include <vector>

using namespace std;

/*
    PROBLEM: Visits vs Target
    
    You are given an array of non-negative integers, visits, which represents how many 
    people visited a website on consecutive days. visits[0] is the number of visitors 
    on the first day, visits[1] is the number of visitors on the second day, and so on.

    Your task is to return the index i of the first day when the total number of visits 
    reaches a given target. In other words, visits[0] + visits[1] + ... + visits[i] >= target.

    If the sum of all daily visits never reaches the target, return -1.

    CONSTRAINTS:
    - 0 <= visits.length <= 1000
    - 0 <= visits[i] <= 10^4
    - 1 <= target <= 10^7
    - Time Limit: 0.5 seconds (C++)

    NOTE:
    A solution with time complexity not worse than O(visits.length^2) will fit within 
    the execution time limit. (Though O(N) is definitely possible!)
*/

int solution(vector<int> visits, int target) {
    // TODO: Write your code here
    int idx=0,n=visits.size();
    int sum=0;
    while(idx<n){
        sum+=visits[idx];
        if(sum>=target) break;
        idx++;
    }
    
    return idx==n ?-1: idx;  // Placeholder return
}

int main() {
    // --- Test Case 1 ---
    // Explanation:
    // Day 0: 300 (Total 300) < 700
    // Day 1: +200 (Total 500) < 700
    // Day 2: +100 (Total 600) < 700
    // Day 3: +200 (Total 800) >= 700 -> Return 3
    vector<int> t1 = {300, 200, 100, 200, 500};
    int target1 = 700;
    cout << "Test Case 1: " << solution(t1, target1) << " (Expected: 3)" << endl;

    // --- Test Case 2 ---
    // Explanation: Day 0 is 900, which is >= 900 immediately.
    vector<int> t2 = {900, 821, 1090};
    int target2 = 900;
    cout << "Test Case 2: " << solution(t2, target2) << " (Expected: 0)" << endl;

    // --- Test Case 3 ---
    // Explanation: Total sum is 700+800+500 = 2000. 
    // 2000 < 2001. Target never reached.
    vector<int> t3 = {700, 800, 500};
    int target3 = 2001;
    cout << "Test Case 3: " << solution(t3, target3) << " (Expected: -1)" << endl;

    return 0;
}