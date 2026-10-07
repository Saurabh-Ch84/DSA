#include<bits/stdc++.h>
using namespace std;

bool check(long long mid, long long k, const vector<int> &a, int n) {
    long long operationsNeeded = 0;
    int medIndex = n / 2;
    for (int i = medIndex; i < n; i++) {
        if (a[i] < mid) operationsNeeded += (mid - a[i]);
        if (operationsNeeded > k) return 0;
    }
    return 1;
}

long long maxMedianPossible(vector<int> &a, int n, long long k) {
    sort(a.begin(), a.end());
    long long low = a[n / 2], high = a[n / 2] + k, ans = low;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, k, a, n)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<maxMedianPossible(a,n,k);
    return 0;
}