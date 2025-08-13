#include<iostream>
#include<vector>
using namespace std;

class Solution{
    
    void mergeSort(vector<int> &v, int low, int high){
        if (low >= high) return ;
        int mid = (high + low) / 2;
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);
        merge(v, low, mid, high);
    }

    void merge(vector<int> &v,int low,int mid,int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        while(left<=mid && right<=high){
            if(v[left]<v[right]) temp.push_back(v[left++]);
            else temp.push_back(v[right++]);
        }
        while(left<=mid)
            temp.push_back(v[left++]);
        while(right<=high)
            temp.push_back(v[right++]);
        for(int i=low;i<=high;i++)
            v[i]=temp[i-low];
    }

    void print(const vector<int> &v){
        for(int val:v)
            cout<<val<<" ";
        cout<<endl;
    }
        public:
    void sort(vector<int> &v){
        print(v);
        mergeSort(v,0,v.size()-1);
        print(v);
    }
};

int main()
{
    Solution s;
    vector<int> v1={1,2,6,7,1};
    vector<int> v2={11,-2,6,7,0};
    vector<int> v3={110,-2,-6,97,11};
    s.sort(v2);

    return 0;
}