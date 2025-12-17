#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

/*
    PROBLEM: Longest Contiguous Segment (Question 4)
    
    You are monitoring building density on a number line.
    Given an array 'queries' representing locations of new houses appearing one by one.
    
    After EACH house is built, return the length of the LONGEST segment of 
    contiguous (neighboring) houses currently in the district.

    CONSTRAINTS:
    - 1 <= queries.length <= 10^5
    - -10^9 <= queries[i] <= 10^9 (Coordinates can be large/negative!)
    - Time Limit: 0.5 seconds
    - Memory Limit: 1 GB
    
    CRITICAL NOTE:
    It is guaranteed that no house is built at a point that has existing houses 
    on BOTH its immediate left (x-1) and immediate right (x+1).
    (Meaning: You never fill a gap. You only extend an existing segment or start a new one.)

    INPUT:
    - queries: vector<int>

    OUTPUT:
    - vector<int>: Array of max segment lengths after each query.
*/

vector<int> solution(vector<int> queries) {
    vector<int> result;
    unordered_map<int,int> hashMap;
    int maxi=0;
    for(int &query: queries){
        int val=query;
        int leftLen=(hashMap.count(val-1))? hashMap[val-1]:0;
        int rightLen=(hashMap.count(val+1))? hashMap[val+1]:0;
        int newLen=1+leftLen+rightLen;
        maxi=max(maxi,newLen);
        result.push_back(maxi);
        hashMap[val]=newLen;
        hashMap[val-leftLen]=newLen;
        hashMap[val+rightLen]=newLen;
    }
    return result;
}

int main() {
    // --- Test Case 1 ---
    // Explanation:
    // Build 2: {2} -> Max 1
    // Build 1: {1, 2} -> Max 2
    // Build 3: {1, 2, 3} -> Max 3
    vector<int> q1 = {2, 1, 3};
    vector<int> res1 = solution(q1);
    
    cout << "Test Case 1 Result: ";
    for(int x : res1) cout << x << " ";
    cout << " (Expected: 1 2 3)" << endl;

    // --- Test Case 2 ---
    // Explanation:
    // Build 1: {1} -> Max 1
    // Build 3: {1}, {3} -> Max 1 (Segments are 1 and 1)
    // Build 0: {0, 1}, {3} -> Max 2 (Segment 0-1 has len 2)
    // Build 4: {0, 1}, {3, 4} -> Max 2 (Both segments len 2)
    vector<int> q2 = {1, 3, 0, 4};
    vector<int> res2 = solution(q2);
    
    cout << "Test Case 2 Result: ";
    for(int x : res2) cout << x << " ";
    cout << " (Expected: 1 1 2 2)" << endl;

    return 0;
}