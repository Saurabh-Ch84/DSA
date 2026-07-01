#include <bits/stdc++.h>
using namespace std;

void getAns(vector<int> &arr,int n){
    vector<int> res;
    int prev=-1, i=0, flag=true;
    while(i<n){
        if(i==n-1 || arr[i]!=arr[i+1]){
            res.push_back(arr[i]);
            prev=arr[i];
        }
        else{
            if(arr[i]<=2){
                flag=false;
                cout<<-1;
                return;
            }
            else{
                if(prev==1){
                    res.push_back(arr[i]-1);
                    res.push_back(1);
                    prev=1;
                }
                else{
                    res.push_back(1);
                    res.push_back(arr[i]-1);
                    prev=arr[i]-1;
                }
            }
            
        }
        i++;
    }
    if(flag) cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        getAns(arr,n);
        cout<<endl;
    }
    return 0;
}
