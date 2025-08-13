#include<iostream>
#include<vector>
using namespace std;

class Solution{
    void print(const vector<int> &a){
        for(int &val:a)
            cout<<val<<" ";
        cout<<endl;
    }
        public:
    vector<int> removeDup(vector<int> &arr){
        int left=0,n=arr.size(),right=1;
        while(right<n){
            if(arr[left]!=arr[right])
                arr[++left]=arr[right];
            right++;
        }
        cout<<left+1<<endl;
        arr.resize(left+1);
        print(arr);
        return arr;
    }
};

int main(){
    Solution s;
    vector<int> v1={1,2,3,4};
    vector<int> v2={1,1,3,4};
    vector<int> v3={1,1,2,2};
    vector<int> v4={1,2,3,3,3};
    vector<int> v5={1,2,3,3,3,4,4,4,4,4,6,7,8,9};
    s.removeDup(v5);
return 0;
}