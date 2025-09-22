#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    It can be observed that sides a, b, c, and d form a valid quadrilateral only if the sum of three 
    smaller sides is greater than or equal to the largest side, or the perimeter of the 
    quadrilateral is greater than or equal to (2 * largest side). 
*/

class Solution{
    bool isValid(int a,int b,int c,int d){
        return (a+b+c+d)>=(2*d);
    }
    // Brute-Force
        public:
    int maxPerimeterOfQuadilateral1(vector<int> &nums){
        int n=nums.size();
        if(n<4) return -1;
        sort(begin(nums),end(nums));

        int maxPeri=-1,aPtr=0;
        while(aPtr<n){
            if(aPtr!=0 && nums[aPtr]==nums[aPtr-1]){
                aPtr++;
                continue;
            }
            int bPtr=aPtr+1;
            while(bPtr<n){
                int cPtr=bPtr+1;
                while(cPtr<n){
                    int dPtr=n-1;
                    while(dPtr!=cPtr){
                        if(isValid(nums[aPtr],nums[bPtr],nums[cPtr],nums[dPtr])){
                            maxPeri=max(maxPeri,nums[aPtr]+nums[bPtr]+nums[cPtr]+nums[dPtr]);
                            break; //sorted property
                        }
                        else dPtr--;
                    }
                    cPtr++;
                }
                bPtr++;
            }   
            aPtr++;
        }
        return maxPeri;
    }

    // optimal 
    int maxPerimeterOfQuadilateral2(vector<int> &nums){
        int n=nums.size();
        if(n<4) return -1;
        sort(begin(nums),end(nums));
        int maxPeri=-1;
        
        int a=-1,b,c,d;
        for(int i=n-4;i>=0;i--){
            if(a==-1){
                a=nums[i],b=nums[i+1],c=nums[i+2],d=nums[i+3];
            }
            else{
                d=c;
                c=b;
                b=a;
                a=nums[i];
            }
            if(isValid(a,b,c,d)){
                maxPeri=a+b+c+d;
                break;
            }
        }
        return maxPeri;
    }
};

int main(){
    Solution s;
    vector<int> nums={3,1,2,4,2,1};
    cout<<s.maxPerimeterOfQuadilateral2(nums);
return 0;
}