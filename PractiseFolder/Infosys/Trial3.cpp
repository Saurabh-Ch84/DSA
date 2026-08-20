#include<bits/stdc++.h>
using namespace std;

/*
        Clipping Points in an Array

        An internal element is a clipping point if it is either greater than both neighbours or smaller 
        than both neighbours. Remove one element so that the number of remaining clipping points is minimum.

    Example:
    [1, 5, 2, 4, 3]
    The clipping points are 5, 2 and 4. Removing 2 gives [1, 5, 4, 3], which has only one clipping point.

*/

class Solution{
    int isClippingPoint(int a,int b,int c){
        if(b<a && b<c) return -1;
        if(b>a && b>c) return 1;
        return 0;
    }
        public:
    int minimiseClippingPoints(vector<int> arr){
        int n=arr.size(), count=0;
        vector<int> clipPoint(n,0);
        for(int i=1;i<n-1;i++){
            int check=isClippingPoint(arr[i-1],arr[i],arr[i+1]);
            if(check){
                count++;
                clipPoint[i]=check;
            }
        }
        if(!count) return 0;
        int mini=count;
        for(int i=0;i<n;i++){
            if(i==0){
                if(clipPoint[i+1]) mini=min(mini,count-1);
            }
            else if(i==n-1){
                if(clipPoint[i-1]) mini=min(mini,count-1);
            }
            else{
                int oldPoints=(clipPoint[i]? 1:0)+(clipPoint[i+1]? 1:0)+(clipPoint[i-1]? 1:0);
                int newPoints=(i-2>=0 && isClippingPoint(arr[i-2],arr[i-1],arr[i+1])? 1:0)+(i+2<n && isClippingPoint(arr[i-1],arr[i+1],arr[i+2])? 1:0);
                int newCount=count-oldPoints+newPoints;
                mini=min(mini,newCount);
            }
        }
        return mini;
    }
};



int main(){
    Solution s;
    cout<<s.minimiseClippingPoints({1,5,2,4,3})<<endl;
return 0;
}