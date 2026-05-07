#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums,int target,int start) {
        int n=nums.size(), left=start, right=start;
        while(left>=0 || right<n){
            int leftVal=(left>=0? nums[left]: -1);
            int rightVal=(right<n? nums[right]: -1);
            if(target==leftVal)
                return abs(left-start);
            if(target==rightVal)
                return abs(right-start);
            left--, right++;
        }
        return -1;
    }
};

class Solution {
  public:
  
    bool all9s(vector<int>& num) {
        for (int d : num) {
            if (d != 9) return false;
        }
        return true;
    }
    
    vector<int> nextPalindrome(vector<int>& num) {
        // code here
        int n = num.size();

        if (all9s(num)) {
            vector<int> ans(n + 1, 0);
            ans[0] = ans[n] = 1;
            return ans;
        }
    
        vector<int> ans = num;
    
        int mid = n / 2;
        int i = mid - 1;
        int j = (n % 2) ? mid + 1 : mid;
    
        bool leftSmaller = false;
    
        while (i >= 0 && ans[i] == ans[j]) {
            i--;
            j++;
        }
    
        if (i < 0 || ans[i] < ans[j]) {
            leftSmaller = true;
        }
    
        while (i >= 0) {
            ans[j] = ans[i];
            i--;
            j++;
        }
    
        if (leftSmaller) {
            int carry = 1;
    
            i = mid - 1;
    
            if (n % 2 == 1) {
                ans[mid] += carry;
                carry = ans[mid] / 10;
                ans[mid] %= 10;
                j = mid + 1;
            } else {
                j = mid;
            }
    
            while (i >= 0) {
                ans[i] += carry;
                carry = ans[i] / 10;
                ans[i] %= 10;
    
                ans[j] = ans[i];
                i--;
                j++;
            }
        }
    
        return ans;
    }
};

int main(){

return 0;
}