#include <bits/stdc++.h>

using namespace std;
using vint=vector<int>;
using vvint=vector<vint>;
using pii=pair<int,int>;

class Solution{
    vint arr;
    struct Comp{
        bool operator()(const vint &a,const vint &b) const{
            if(a[1]!=b[1])
                return a[1]<b[1];
            return a[0]<b[0];
        }
    };
    
    bool isOverLapping(vint &a,vint &b){
        return (a[0]<=b[0] && b[0]<a[1]);
    }
        public:
    Solution(){}
    
    void setArr(vint &arr){
        this->arr=arr;
    }
    
    int findAns() {
    int n = arr.size();
    vvint badSubArrays;

    // 1. O(N^2) Optimized Discovery
    for (int i = 0; i < n; i++) {
        unordered_map<int, int> freqMap;
        int uniqueCount = 0; // Tracks elements that appear EXACTLY once

        for (int j = i; j < n; j++) {
            int val = arr[j];
            freqMap[val]++;

            // Update our unique counter dynamically
            if (freqMap[val] == 1) {
                uniqueCount++; // It's a new unique element
            } else if (freqMap[val] == 2) {
                uniqueCount--; // It appeared again, no longer unique!
            }

            // If NO elements are unique, every element appears >= 2 times
            if (uniqueCount == 0) {
                badSubArrays.push_back({i, j});
            }
        }
    }

    if (badSubArrays.empty()) return 0;

    // 2. Sort by end-time using your custom comparator
    sort(badSubArrays.begin(), badSubArrays.end(), Comp());

    // 3. Fixed Greedy Interval Scheduling
    int count = 1;
    int lastEnd = badSubArrays[0][1]; // Track the end of the LAST SELECTED interval

    for (int i = 1; i < badSubArrays.size(); i++) {
        // Since intervals are inclusive [i, j], they are disjoint ONLY IF
        // the new start is strictly greater than the last selected end.
        if (badSubArrays[i][0] > lastEnd) {
            count++;
            lastEnd = badSubArrays[i][1]; // Update our tracked end marker
        }
    }

    return count;
}
};

int main() {
	// your code goes here
    int t;
    Solution s;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vint temp;
        for(int j=0;j<n;j++){
            int val;
            cin>>val;
            temp.push_back(val);
        }
        s.setArr(temp);
        cout<<s.findAns()<<endl;
    }
}