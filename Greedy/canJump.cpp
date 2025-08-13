#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump1(vector<int>& nums) 
    {
        if(nums.size()==1)
            return true;    
        return makeJump1(nums,0,nums.size()-1);
    }
    bool makeJump1(vector<int> nums,int idx,int target)
    {
        cout<<"1";
        if(idx==target)
            return true;
        if(nums[idx]>target-idx)
            return true;    
        bool ans;
        for(int i=nums[idx];i>=1;i--){
            ans=makeJump1(nums,idx+i,target);
            if(ans==1)
                return true;
        }
        return false;
    }

    bool canJump2(vector<int>& nums) 
    {
        if(nums.size()==1)
            return true;    
        return makeJump2(nums,0,nums.size()-1);
    }
    bool makeJump2(vector<int> nums,int idx,int target)
    {
        cout<<"1";
        if(idx==target)
            return true;
        if(nums[idx]>target-idx)
            return true;    
        bool ans;
        for(int i=1;i<=nums[idx];i++){
            ans=makeJump2(nums,idx+i,target);
            if(ans==1)
                return true;
        }
        return false;
    }

    bool canJump(vector<int>& nums) 
    {
        int max_reach = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] + i > max_reach)
                max_reach = nums[i] + i;
            if(max_reach == i)
                break;
        }
        return max_reach >= nums.size()-1;
    }
};


int main(){
    Solution *obj=new Solution();
    vector<int> v;
    int s;
    cout<<"Size:";
    cin>>s;
    for (int i = 0; i < s; i++)
    {
        int ptr;
        cin>>ptr;
        v.push_back(ptr);
    }
    cout<<"back-loop Version"<<endl;
    if(obj->canJump1(v))
        cout<<"\nIt's possible to jump from index 0 to index "<<v.size()-1<<endl;
    else
        cout<<"It's impossible to jump from index 0 to index "<<v.size()-1<<endl;

    cout<<"front-loop Version"<<endl;
    if(obj->canJump2(v))
        cout<<"\nIt's possible to jump from index 0 to index "<<v.size()-1<<endl;
    else
        cout<<"It's impossible to jump from index 0 to index "<<v.size()-1<<endl;
return 0;
}