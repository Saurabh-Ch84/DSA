#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//optimal version
class SolutionUnion {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        int left=0,right=0,n=a.size(),m=b.size();
        vector<int> result;
        result.push_back(min(a[0],b[0]));
        
        while(left<n && right<m){
            if(a[left]<=b[right]){
                if(result.back()!=a[left]) 
                    result.push_back(a[left]);
                left++;
            }
            else
            {
                if(result.back()!=b[right]) 
                    result.push_back(b[right]);
                right++;
            }
        }
        while(left<n){
            if(result.back()!=a[left])
                result.push_back(a[left]);
            left++;
        }
        
        while(right<m){
            if(result.back()!=b[right])
                result.push_back(b[right]);
            right++;
        }
            
        return result;
        // return vector with correct order of elements
    }
};

//for sorted arrays
class SolutionIntersection2 {
  public:
    // Function to return a list containing the intersection of two arrays.
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        // Your code here
        vector<int> result;
        int left=0,right=0;
        int n=arr1.size(),m=arr2.size();
        while(left<n && right<m){
            if(arr1[left]!=arr2[right]){
                if(arr1[left]<arr2[right]) left++;
                else right++;
            }
            else{
                if(result.empty() || result.back()!=arr1[left])
                    result.push_back(arr1[left]);
                left++;
                right++;
            }
        }
        return result;
    }
};

//for non-sorted arrays
class SolutionIntersection {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        if(m<n) return intersection(nums2,nums1);
        unordered_set<int> numsSet;
        vector<int> result;
        for(int &ele:nums1)
            numsSet.insert(ele);
        
        for(int &ele:nums2){
            if(numsSet.count(ele)){
                result.push_back(ele);
                numsSet.erase(ele);
            }
        }
        return result;
    }
};

int main(){

return 0;
}