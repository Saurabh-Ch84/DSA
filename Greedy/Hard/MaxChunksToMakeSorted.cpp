#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int maxChunksToSorted(vector<int>& arr){
        int n=arr.size(), count=0, sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(2*sum==(i)*(i+1))
                count++;
        }
        return count;
    }
};

class Solution2 {
    using vint=vector<int>;
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vint suffixMin(n);
        suffixMin[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
            suffixMin[i]=min(arr[i],suffixMin[i+1]);
        int chunks=0, maxi=-1;
        for(int i=0;i<n;i++){
            if(maxi<=suffixMin[i]) chunks++;
            maxi=max(maxi,arr[i]);
        }
        return chunks;
    }
};

int main(){

return 0;
}