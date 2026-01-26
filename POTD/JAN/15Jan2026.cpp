#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using vi = vector<int> ;
class Solution {
  public:
    int minCandy(vi &arr) {
        // code here
        int n=arr.size();
        if(n<=1) return n;
        vi candy(n,1);
        
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1])
                candy[i]=candy[i-1]+1;
        }
        
        int mini=candy.back();
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1])
                candy[i]=max(candy[i],candy[i+1]+1);
            mini+=candy[i];
        }
        return mini;
    }
};

class Solution {
    int findMaxConsecutiveSubArraySize(vector<int> &bars){
        sort(bars.begin(),bars.end());
        int side=0, n=bars.size(), ptr=0;
        while(ptr<n){
            int count=1;
            while(ptr<n-1 && bars[ptr+1]==bars[ptr]+1){
                count++;
                ptr++;
            }
            side=max(side,count);
            ptr++;
        }
        return side;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int side1=findMaxConsecutiveSubArraySize(hBars)+1;
        int side2=findMaxConsecutiveSubArraySize(vBars)+1;
        int mini=min(side1,side2);
        return mini*mini;
    }
};

int main(){

return 0;
}