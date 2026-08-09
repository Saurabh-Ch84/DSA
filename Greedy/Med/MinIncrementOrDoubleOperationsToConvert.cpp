#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
        int n=arr.size(), odd=0, sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2==1) odd++;
            sum+=arr[i];
        }
        int count=0;
        while(sum){
            if(!odd){
                sum=sum/2;
                count++;
                for(int i=0;i<n;i++){
                    arr[i]=arr[i]/2; // this handles the case for odd numbers as well, 
                    // since odd numbers will become even after division by 2
                    if(arr[i]%2==1) odd++;
                }
            }
            else{
                sum-=odd;
                count+=odd;
                odd=0;
                // no need to update arr here, cause the next iteration will update the odd numbers again.
            }
        }
        return count;
    }
};

int main(){

return 0;
}