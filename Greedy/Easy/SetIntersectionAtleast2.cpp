#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
    struct Comp{
        bool operator()(const vector<int> &a,const vector<int> &b){
            if(a[1]==b[1]) return a[0]>b[0];
            return a[1]<b[1];
        }
    };
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),Comp());

        int first=-1,second=-1,ans=0;
        for(vector<int> &interval: intervals){
            int left=interval[0],right=interval[1];
            if(left<=first){
                continue;
            }
            else if(left>second){
                ans+=2;
                first=right-1;
                second=right;
            }
            else{
                ans+=1;
                first=second;
                second=right;
            }
        }

        return ans;
    }
};


class Solution2 {
    struct Comp{
        bool operator()(const vector<int> &a,const vector<int> &b){
            if(a[1]==b[1]) return a[0]>b[0];
            return a[1]<b[1];
        }
    };
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),Comp());

        int left=-1,right=-1,ans=0;
        for(vector<int> &interval: intervals){
            int start=interval[0],end=interval[1];
            if(start>left && start<=right){
                ans+=1;
                left=right;
                right=end;
            }
            else if(start>right){
                ans+=2;
                left=end-1;
                right=end;
            }
        }
        return ans;
    }
};
int main(){

return 0;
}