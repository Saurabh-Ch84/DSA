#include<bits/stdc++.h>
using namespace std;

class Solution {
    using vint=vector<int>;
    using pii=pair<int,int>;
    using vpii=vector<pii>;
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int n=a.size(), m=b.size();
        
        vint prefixA(n,0), prefixB(m,0);
        prefixA[0]=a[0], prefixB[0]=b[0];
        for(int i=1;i<n;i++)
            prefixA[i]=prefixA[i-1]+a[i];
        for(int i=1;i<m;i++)
            prefixB[i]=prefixB[i-1]+b[i];
        
        vpii arr;
        arr.push_back({-1,-1});
        int i=0, j=0;
        while(i<n && j<m){
            if(a[i]==b[j]){
                arr.push_back({i,j});
                i++;
            }
            else if(a[i]<b[j]) i++;
            else j++;
        }
        arr.push_back({n-1,m-1});
        
        int sum=0, k=arr.size();
        for(int i=1;i<k;i++){
            int segmentA=prefixA[arr[i].first]-(i>1? prefixA[arr[i-1].first]: 0);
            int segmentB=prefixB[arr[i].second]-(i>1? prefixB[arr[i-1].second]: 0);
            sum+=max(segmentA,segmentB);
        }
        return sum;
    }
};

class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int n=a.size(), m=b.size();
        int i=0, j=0, sum=0, currSumA=0, currSumB=0;
        while(i<n && j<m){
            if(a[i]==b[j]){
                sum+=max(currSumA,currSumB)+a[i];
                currSumA=0, currSumB=0;
                i++, j++;
            }
            else if(a[i]<b[j]){
                currSumA+=a[i];
                i++;
            }
            else{
                currSumB+=b[j];
                j++;
            }
        }
        while(i<n) currSumA+=a[i++];
        while(j<m) currSumB+=b[j++];
        return sum+max(currSumA,currSumB);
    }
};

int main(){

return 0;
}