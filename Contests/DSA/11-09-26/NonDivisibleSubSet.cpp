#include<bits/stdc++.h>
using namespace std;

int nonDivisibleSubset(int k, vector<int> s) {
    vector<int> remArr(k,0);
    for(int &num: s){
        int rem=num%k;
        remArr[rem]++;
    }
    int count=0, left=0;
    while(left<=k/2){
        if(left==0 && remArr[left]) count++;
        else{
            int right=k-left;
            if(right==left){
                if(remArr[left]) count++;
            }
            else count+=max(remArr[left],remArr[right]);
        }
        left++;
    }
    return count;
}

int main(){

return 0;
}