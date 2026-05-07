#include<iostream>
#include<vector>
using namespace std;

class Solution {
    using vint=vector<int>;
    using vvint=vector<vint>;
  public:
    vint findMean(vint &arr,vvint &queries) {
        // code here
        int n=arr.size();
        vint prefixSum(n,0);
        prefixSum[0]=arr[0];
        
        for(int i=1;i<n;i++)
            prefixSum[i]=prefixSum[i-1]+arr[i];
        
        vint res;
        for(vint &q: queries){
            int l=q[0], r=q[1];
            int sum=prefixSum[r]-(l>0? prefixSum[l-1]: 0);
            int avg=sum/(r-l+1);
            res.push_back(avg);
        }
        return res;
    }
};

class Solution {
    using vstr=vector<string>;
    bool matchedWithTwoEdits(string &a,string &b){
        int n=a.length(), count=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]) count++;
            if(count>2) return false;
        }
        return true;
    }
public:
    vector<string> twoEditWords(vstr &queries,vstr &dictionary) {
        int n=queries.size(), m=dictionary.size();
        vstr result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matchedWithTwoEdits(queries[i],dictionary[j])){
                    result.push_back(queries[i]);
                    break;
                }
            }
        }
        return result;
    }
};

int main(){

return 0;
}