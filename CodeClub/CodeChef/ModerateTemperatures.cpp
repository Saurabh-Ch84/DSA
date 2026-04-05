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
        int maxi=*max_element(arr.begin(),arr.end());
        int mini=*min_element(arr.begin(),arr.end());
        int count=0;
        for(int &v: arr){
            if(v!=maxi && v!=mini)
                count++;
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
