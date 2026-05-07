#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;

    int manhattanDist(vint &a,vint &b){
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    bool tryWithStart(int mid,int k,int m,int start,vvint &distance){
        int count=1, curr=start;
        while(count<k && curr<m){
            int low=curr+1, high=m-1, ans=-1;
            while(low<=high){
                int mid_=low+(high-low)/2;
                if(manhattanDist(distance[curr],distance[mid_])>=mid){
                    ans=mid_;
                    high=mid_-1;
                }
                else low=mid_+1;
            }
            if(ans!=-1){
                curr=ans;
                count++;
            }
            else return false;
        }
        return (count>=k && curr<m && manhattanDist(distance[start],distance[curr])>=mid);
    }

    bool check(int mid1,int k,int m,vvint &distance){
        int start=0, end=start;
        int low=start, high=m-1;
        while(low<=high){
            int mid2=low+(high-low)/2;
            if(manhattanDist(distance[start],distance[mid2])>=mid1){
                end=mid2;
                high=mid2-1;
            }
            else low=mid2+1;
        }
        for(int i=start;i<end;i++){
            if(tryWithStart(mid1,k,m,i,distance))
                return true;
        }
        return false;
    }
public:
    int maxDistance(int side,vvint &points,int k) {
        int n=points.size();
        vvint horizontal1, horizontal2, vertical1, vertical2;

        for(vint &point: points){
            int x=point[0], y=point[1];
            if(y==side) horizontal1.push_back(point);
            else if(x==side) vertical1.push_back(point);
            else if(!y) horizontal2.push_back(point);
            else vertical2.push_back(point);
        }

        sort(horizontal1.begin(),horizontal1.end());
        sort(vertical1.rbegin(),vertical1.rend());
        sort(horizontal2.rbegin(),horizontal2.rend());
        sort(vertical2.begin(),vertical2.end());

        vvint distance;
        distance.insert(distance.end(),horizontal1.begin(),horizontal1.end());
        distance.insert(distance.end(),vertical1.begin(),vertical1.end());
        distance.insert(distance.end(),horizontal2.begin(),horizontal2.end());
        distance.insert(distance.end(),vertical2.begin(),vertical2.end());
        int m=distance.size();

        int low=1, high=2*side, ans=-1;
        while(low<=high){
            int mid1=low+(high-low)/2;
            if(check(mid1,k,m,distance)){
                ans=mid1;
                low=mid1+1;
            }
            else high=mid1-1;
        }
        return ans;
    }
};

class Solution {
    bool areOppositeSigns(int &a,int b){
        return ((a<0 && b>0) || (a>0 && b<0));
    }
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            bool flag=true;
            while(!res.empty() && areOppositeSigns(res.back(),arr[i])){
                if(abs(res.back())==abs(arr[i])){
                    res.pop_back();
                    flag=false;
                    break;
                }
                else if(abs(res.back())>abs(arr[i])){
                    flag=false;
                    break;
                }
                else res.pop_back();
            }
            if(flag) res.push_back(arr[i]);
        }
        return res;
    }
};

int main(){

return 0;
}