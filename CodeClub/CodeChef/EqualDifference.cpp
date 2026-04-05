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
        int n=arr.size();
        unordered_map<int,int> hashMap;
        for(int i=0;i<n;i++){
            int v=arr[i]-i;
            hashMap[v]++;
        }
        
        int count=0;
        for(auto &p: hashMap){
            count+=((p.second)*(p.second-1))/2;
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