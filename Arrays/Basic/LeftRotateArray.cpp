#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    void print( vector<int> a){
        for(int &val:a)
            cout<<val<<" ";
        cout<<endl;
    }
        public:
    //Brute
    vector<int> leftRotate1(vector<int> arr,int d){
        int n=arr.size();
        d=d%n;
        for(int k=0;k<d;k++){
            for(int i=0;i<n-1;i++){
                int temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
            }
        }
        print(arr);
        return arr;
    }
    //Better
    vector<int> leftRotate2(vector<int> arr,int d){
        int n=arr.size();
        d=d%n;
        vector<int> temp(d);
        for(int i=0;i<d;i++)
            temp[i]=arr[i];
        for(int i=0;i<n-d;i++)
            arr[i]=arr[i+d];
        for(int i=0;i<d;i++)
            arr[n-d+i]=temp[i];
        print(arr);
        return arr;
    }

    //optimal
    vector<int> leftRotate3(vector<int> arr,int d){
        int n=arr.size();
        d=d%n;
        reverse(arr.begin(),arr.begin()+d);
        reverse(arr.begin()+d,arr.end());
        reverse(arr.begin(),arr.end());
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
    s.leftRotate1(v5,2);
    s.leftRotate2(v5,2);
    s.leftRotate3(v5,2);
return 0;
}