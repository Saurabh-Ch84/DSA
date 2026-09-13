#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int n=arr.size();
        
        int mini=arr[0], negatives=0, maxNegative=-1e9;
        long long nonZeroProduct=1;
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                maxNegative=max(maxNegative,arr[i]);
                negatives++;
            }
            if(arr[i]) nonZeroProduct=nonZeroProduct*arr[i];
            mini=min(mini,arr[i]);
        }
        
        if(!negatives) return mini; // if no negative numbers, return the minimum number
        else if(negatives%2==1) return nonZeroProduct; // if odd number of negative numbers, return the product of all non-zero numbers
        else return nonZeroProduct/maxNegative; // if even number of negative numbers, 
        // return the product of all non-zero numbers divided by the maximum negative number.
    }
};

class Solution2 {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int n=arr.size();
        int negs=0, mini=1e9;
        for(int i=0;i<n;i++){
            if(arr[i]<0) negs++;
            mini=min(mini,arr[i]);
        }
        if(!negs) return mini;
        if(negs%2==1){
            long long product=1;
            for(int i=0;i<n;i++){
                if(!arr[i]) continue;
                product=product*arr[i];
            }
            if(product!=1) return product;
        }
        else{
            long long product=1;
            int maxNeg=-1e9;
            for(int i=0;i<n;i++){
                if(!arr[i]) continue;
                product=product*arr[i];
                if(arr[i]<0) maxNeg=max(maxNeg,arr[i]);
            }
            if(product!=1) return product/maxNeg;
        }
        return 0;
    }
};

class Solution3 {
	int minProductOfK(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n) return -1;
        
        sort(arr.begin(), arr.end());
        
        // Handle potential integer overflow during prefix/suffix product accumulation
        // using double or careful bounds, but long long is standard for products.
        vector<long long> pref(n + 1, 1);
        vector<long long> suff(n + 1, 1);
        
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] * arr[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] * arr[i];
        }
        
        long long minProd = LLONG_MAX;
        
        // i = number of elements from the left end
        for (int i = 0; i <= k; i++) {
            int leftCount = i;
            int rightCount = k - i;
            
            if (leftCount > n || rightCount > n) continue;
            // Prevent pointer collision/overlap in the sorted array
            if (leftCount > 0 && rightCount > 0 && leftCount > n - rightCount) continue;
            
            // Product of arr[0 ... leftCount-1] and arr[n - rightCount ... n-1]
            long long prod = pref[leftCount] * suff[n - rightCount];
            minProd = min(minProd, prod);
        }
        
        return minProd;
    }
public:
    int minProd(vector<int>& arr) {
	    // code here
	    int n=arr.size(), mini=1e9;
	    for(int k=1;k<=n;k++){
	        mini=min(mini,minProductOfK(arr,k));
	    }
        return mini;
    }
};


int main(){

return 0;
}