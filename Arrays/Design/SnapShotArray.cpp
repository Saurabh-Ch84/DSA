#include<iostream>
#include<vector>
using namespace std;

class SnapshotArray {
    using vpii=vector<pair<int,int>>;
    vector<vpii> snapArr;
    int snapId;
public:
    SnapshotArray(int length) {
        snapId=0;
        snapArr.resize(length,vpii(1,{snapId,0}));
    }
    
    void set(int index, int val) {
        if(snapArr[index].back().first==snapId){
            snapArr[index].back().second=val;
            return ;
        }
        snapArr[index].push_back({snapId,val});
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        vpii &arr=snapArr[index];
        int low=0, high=arr.size()-1, ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int sID=arr[mid].first;
            if(sID<=snap_id){
                ans=arr[mid].second;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};


int main(){

return 0;
}