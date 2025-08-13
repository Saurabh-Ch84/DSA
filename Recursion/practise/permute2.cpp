#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//optimal 
class Solution {
    void recursion(vector<int>& nums, vector<int>& temp, vector<bool>& visited,
                   vector<vector<int>>& answer, int end) {
        if (temp.size() == end) {
            answer.push_back(temp);
            return;
        }
        for (int i = 0; i < end; i++) {
            if(visited[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !visited[i-1]) continue;
            temp.push_back(nums[i]);
            visited[i] = true;
            recursion(nums,temp,visited,answer,end);
            visited[i] = false;
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<bool> visited(n, false);
        sort(nums.begin(),nums.end());
        vector<vector<int>> answer;
        recursion(nums,temp,visited,answer,n);
        return answer;
    }
};

//Brute force
class Solution1 {
    void recursion(vector<int>& nums, vector<int>& temp, vector<bool>& visited,
                   set<vector<int>>& uniqueSet, int end) {
        if (temp.size() == end) {
            uniqueSet.insert(temp);
            return;
        }
        for (int i = 0; i < end; i++) {
            if(visited[i]) continue;
            temp.push_back(nums[i]);
            visited[i] = true;
            recursion(nums,temp,visited,uniqueSet,end);
            visited[i] = false;
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<bool> visited(n, false);
        set<vector<int>> uniqueSet;
        recursion(nums,temp,visited,uniqueSet,n);
        vector<vector<int>> answer(uniqueSet.begin(),uniqueSet.end());
        return answer;
    }
};

int main(){

return 0;
}