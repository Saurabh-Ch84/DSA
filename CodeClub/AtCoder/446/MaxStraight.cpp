#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
using vi=vector<int>;

int maxStraight(vi arr){
    int n=arr.size(), maxi=0;
    unordered_map<int,int> hashMap; 
    for(int i=0;i<n;i++){
        int val=arr[i];
        int curr=1+hashMap[val-1];
        maxi=max(maxi,curr);
        hashMap[val] = max(hashMap[val], curr);
    }
    return maxi;
}

int main(){
    cout<<maxStraight({3 ,4 ,3 ,5 ,7 ,6 ,2});
return 0;
}