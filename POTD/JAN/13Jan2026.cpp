#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int n=arr.size(), ptr=0;
        int change5=0, change10=0, change20=0;
        while(ptr<n){
            int note=arr[ptr++];
            if(note==5){
                change5++;
            }
            else if(note==10){
                if(change5) change5--;
                else return false;
                change10++;
            }
            else{
                if(change10){
                    change10--;
                    if(change5) change5--;
                    else return false;
                }
                else if(change5>=3){
                    change5-=3;
                }
                else return false;
                change20++;
            }
        }
        return true;
    }
};

using vi = vector<int> ;

class Solution {
    bool check(double mid,double totalArea,vector<vi> &squares){
        double bottomArea=0;
        for(vi &square: squares){
            double x=square[0], y=square[1], s=square[2];
            if(y+s<=mid) bottomArea+=s*s;
            else if(y<mid && s+y>mid){
                double area=(mid-y)*s;
                bottomArea+=area;
            }
        }
        return (bottomArea>=totalArea/2.0);
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low=1e9, high=0, totalArea=0;
        for(vi &square: squares){
            double x=square[0], y=square[1], s=square[2];
            totalArea+=s*s;
            low=min(low,y);
            high=max(high,y+s);
        }

        double ans=-1;
        while(high-low >= 1e-5){
            double mid=low+(high-low)/2.0;
            bool response=check(mid,totalArea,squares);
            ans=mid;
            if(response) high=mid;
            else low=mid;
        }
        return ans;
    }
};

using vi = vector<int> ;

class Solution {
    bool check(double mid,double totalArea,vector<vi> &squares){
        double bottomArea=0;
        for(vi &square: squares){
            double x=square[0], y=square[1], s=square[2];
            if(y+s<=mid) bottomArea+=s*s;
            else if(y<mid && s+y>mid){
                double area=(mid-y)*s;
                bottomArea+=area;
            }
        }
        return (bottomArea>=totalArea/2);
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low=1e9, high=0, totalArea=0;
        for(vi &square: squares){
            double x=square[0], y=square[1], s=square[2];
            totalArea+=s*s;
            low=min(low,y);
            high=max(high,y+s);
        }
        double ans=-1;
        for(int i=0;i<100;i++){
            double mid=low+(high-low)/2;
            bool response=check(mid,totalArea,squares);
            if(response){
                high=mid;
                ans=mid;
            }
            else low=mid;
        }
        return ans;
    }
};

int main(){

return 0;
}