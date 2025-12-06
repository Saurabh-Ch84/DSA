#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

using vi = vector<int> ;
using pvivs= pair<vi,vector<string>> ;

class TimeMap {
    unordered_map<string,pvivs> hashMap;
public:
    TimeMap(){}
    
    void set(string key, string value, int timestamp) {
        hashMap[key].first.push_back(timestamp);
        hashMap[key].second.push_back(value);
    }
    
    string get(string key, int timestamp) {
        vi &arr=hashMap[key].first;
        int n=arr.size();
        if(!n) return "";

        vector<string> &strs=hashMap[key].second;
        int ansIdx=-1,low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<=timestamp){
                ansIdx=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        if(ansIdx==-1) return "";
        return strs[ansIdx];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main(){

return 0;
}