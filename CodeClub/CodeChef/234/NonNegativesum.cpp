#include <bits/stdc++.h>

using namespace std;
using vint=vector<int>;

class Solution{
    vint arr;
        public:
    Solution(){}
    
    void setArr(vint &arr){
        this->arr=arr;
    }
    
    int findAns(){
        int n=arr.size(), sum=0;
        priority_queue<int,vint,greater<int>> pq;
        for(int i=0;i<n;i++){
            if(arr[i]<0) pq.push(arr[i]);
            sum=sum+arr[i];
        }
        int count=n;
        while(sum<0){
            sum-=pq.top(); pq.pop();
            count--;
        }
        return count;
    }
};

int main() {
	// your code goes here
    int t;
    Solution s;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vint temp;
        for(int j=0;j<n;j++){
            int val;
            cin>>val;
            temp.push_back(val);
        }
        s.setArr(temp);
        cout<<s.findAns()<<endl;
    }
}