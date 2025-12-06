#include<iostream>
#include<vector>
using namespace std;

using vi  = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    vvi insert(vvi &intervals, vi &newInterval) {
        if(newInterval.empty()) return intervals;
        vvi ans;
        int i = 0, n = intervals.size();
        // Step 1: add intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        // Step 2: merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        // Step 3: add remaining intervals
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};


class Solution1 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int left=0,right=intervals.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(intervals[mid][0]==newInterval[0]){
                right=mid;
                break;
            }
            else if(intervals[mid][0]>newInterval[0]) right=mid-1;
            else left=mid+1;
        }
        for(int i=0;i<=right;i++)
            answer.push_back(intervals[i]);
            
        bool flag=true;
        if(right==-1){
            answer.push_back(newInterval);
            right=0;
            flag=false;
        }

        for(int i=right;i<intervals.size();i++){
            if(i==right && flag){
                if(newInterval[0]>=answer[i][0] && newInterval[0]<=answer[i][1])
                {
                    answer[i][0]=min(answer[i][0],newInterval[0]);
                    answer[i][1]=max(answer[i][1],newInterval[1]);
                }
                else answer.push_back(newInterval);
            }
            else{
                vector<int> a=answer.back();
                if(intervals[i][0]>=a[0] && intervals[i][0]<=a[1]){
                    answer.pop_back();
                    a[0]=min(intervals[i][0],a[0]);
                    a[1]=max(intervals[i][1],a[1]);
                    answer.push_back(a);
                }
                else{
                    for(int j=i;j<intervals.size();j++)
                        answer.push_back(intervals[j]);
                    return answer;
                }
            }
        }
        return answer;
    }
};

class Solution2 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int n=intervals.size(),i=0;
        while(i<n && newInterval[0]>intervals[i][1]){
            answer.push_back(intervals[i++]);
        }
        while(i<n && newInterval[1]>=intervals[i][0]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i++][1]);
        }
        answer.push_back(newInterval);
        while(i<n){
            answer.push_back(intervals[i++]);
        }
        return answer;
    }
};

int main(){

return 0;
}