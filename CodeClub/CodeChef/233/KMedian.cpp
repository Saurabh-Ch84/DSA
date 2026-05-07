#include <bits/stdc++.h>

using namespace std;
using vint=vector<int>;

class Solution{
    int n,k;
    vint arr;
        public:
    Solution(){}
    
    void setArr(vint &a,int n,int k){
        arr=a;
        this->n=n;
        this->k=k;
        sort(arr.begin(),arr.end());
    }
    
    void findNums() {
        int rem = n - k;
        int left = rem / 2, right = rem / 2;
        if (rem % 2 == 0) left--;
    
        int lastPrinted = -1; // Keep track of the last printed median to avoid duplicates
        bool first = true;
    
        for (int i = 0; i < n; i++) {
            // If we have AT LEAST enough elements on both sides to form the remaining array
            if (i >= left && (n - 1 - i) >= right) {
                // Print only if it's the first valid median, or different from the last one
                if (first || arr[i] != lastPrinted) {
                    cout << arr[i] << " ";
                    lastPrinted = arr[i];
                    first = false;
                }
            }
        }    
        cout << "\n";
    }
};

int main() {
	// your code goes here
    int t;
    Solution s;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        vint temp;
        for(int j=0;j<n;j++){
            int val;
            cin>>val;
            temp.push_back(val);
        }
        s.setArr(temp,n,k);
        s.findNums();
    }
}