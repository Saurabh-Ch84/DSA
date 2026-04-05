#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution1 {
public:
    int bitwiseComplement(int n) {
        if(!n) return 1;
        int n_=0, firstSetBit=-1;
        for(int i=31;i>=0;i--){
            int bit=(n>>i) & 1;
            if(bit && firstSetBit==-1) firstSetBit=i;
            if(firstSetBit!=-1) n_=(n_<<1) | !bit;
        }
        return n_;
    }
};

using vint=vector<int>;
class Solution2 {
    void getNSE(vint &nse,vint &arr,int n){
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
            if(!s.empty()) nse[i]=s.top();
            s.push(i);
        }
    }
    
    int recursion(vint &nse,vint &arr,int i,int m){
        if(!m) return 0;
        return (nse[i]-i)*arr[i]+recursion(nse,arr,nse[i],m-(nse[i]-i));
    }
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n=arr.size(), sum=0;
        vint nse(n,n);
        getNSE(nse,arr,n);
        
        for(int i=0;i<n;i++){
            int m=n-i;        
            sum+=recursion(nse,arr,i,m);
        }    
        return sum;
    }
};

int main(){

return 0;
}