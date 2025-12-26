#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
using vi = vector<int> ;
using vvi = vector<vi> ;

// It's Halloween night! You and your friends are getting ready to go out in the streets to get as much candy as possible.
// You noticed that every year most of the night was wasted walking to the different streets, but this year will be different:
// you will be driving around the city for candy.
//
// Unfortunately starting up the car and stopping will also take a lot of time and many police officers will be around
// the neighborhood to ensure everyone's safety, so you decide on the following plan:
//
// Once getting out of the car, you must visit at least n houses in a row(You could however start anywhere on the street).
// You will only get out of the car once per street.
// You can only visit k streets at most.
// With the data you've acquired from the previous years, you and your friends know how much candy each house will give.
// This data is denoted by streets, where streets[i][j] represents the amount of candy given by the jth house on the ith street.

// Your task is to find the total amount of candy you can get by visiting as many as k streets,
// stopping once to visit at least n houses in a row.

// Example:
//          For streets = [[1, 6, -50, 9, 0], [5,4,3,-3,2]], n = 3, and k = 1,
//          the output should be speedingForCandy(streets, n, k) = 12.
//          Here is the maximum amount of candy you can get in each street:
//          https://i.imgur.com/nbVsNzq.png
//          You and your friends are only visiting 1 street maximum, so you can ignore the first street,
//          which will not be beneficial for the night.

int maxSumSubArrayOfAtleastNSize(int n,vi &arr){
    int m=arr.size();
    if(m<n) return INT_MIN;
    int left=0,right=0;
    int maxSum=INT_MIN, sum=0, lastSum=0;
    while(right<m){
        sum+=arr[right];
        if(right-left+1==n){
            maxSum=max(maxSum, sum);
        }
        else if(right-left+1>n){
            maxSum=max(maxSum, sum);
            lastSum+=arr[left];
            left++;
            if(lastSum<0){
                sum-=lastSum;
                lastSum=0;
                maxSum=max(maxSum, sum);
            }
        }
        right++;
    }
    return maxSum;
}


int speedingForCandy(vvi &streets, int n, int k){  
    priority_queue<int,vi,greater<int>> pq;
    for(vi &street: streets){
        int ans=maxSumSubArrayOfAtleastNSize(n,street);
        if(pq.size()==k){
            if(ans>pq.top()){
                pq.pop();
                pq.push(ans);
            }
        }
        else pq.push(ans);
    }

    int sum=0;
    while(!pq.empty()){
        int temp=pq.top();
        pq.pop();
        if(temp<=0) continue;
        sum+=temp;
    }
    return sum;
}

int main(){

return 0;
}