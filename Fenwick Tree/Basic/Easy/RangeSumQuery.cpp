#include<iostream>
#include<vector>
using namespace std;

class NumArray {
    vector<int> BIT,copy;
    int n;
    void build(vector<int> &nums){
        for(int i=0;i<n;i++) update(i,nums[i]);
    }
    int query(int index){
        index++;
        int sum=0;
        while(index>0){
            sum+=BIT[index];
            index=index-(index & -index);
        }
        return sum;
    }
    void updateBIT(int index,int val){
        index++;
        while(index<=n){
            BIT[index]+=val;
            index=index+(index & -index);
        }
    }
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        copy.resize(n,0);
        BIT.resize(n+1,0); 
        build(nums);
    }
    void update(int index, int val){
        int delta=val-copy[index];
        copy[index]=val;
        updateBIT(index,delta);
    }
    int sumRange(int left, int right){
        return query(right)-query(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main(){

return 0;
}