#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        int xor1=0,xor2=0;
        for(int i=1;i<=n;i++){
            xor1=xor1^i;
            xor2=xor2^arr[i-1];
        }
        
        int xorResult=xor1^xor2;
        int rightMostSetBit=xorResult & ~(xorResult-1);
        int zeroBucket=0,oneBucket=0;
        
        for(int i=0;i<n;i++){
            if(rightMostSetBit & arr[i]) oneBucket=oneBucket^arr[i];
            else zeroBucket=zeroBucket^arr[i];
        }
        
        for(int i=1;i<=n;i++){
            if(rightMostSetBit & i) oneBucket=oneBucket^i;
            else zeroBucket=zeroBucket^i;
        }
        
        int repeatingNum=-1,missingNum=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==zeroBucket){
                repeatingNum=zeroBucket;
                missingNum=oneBucket;
                break;
            }
            else if(arr[i]==oneBucket){
                repeatingNum=oneBucket;
                missingNum=zeroBucket;
                break;
            }
        }
        return {repeatingNum,missingNum};
    }
};

//optimal solution
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int xor1=0,xor2=0,n=arr.size();
        for(int i=1;i<=n;i++){
            xor1=xor1^i;
            xor2=xor2^arr[i-1];
        }
        int xorRes=xor1^xor2;
        int bit=xorRes&-xorRes;
        int zeroBucket=0,oneBucket=0;
        
        for(int i=1;i<=n;i++){
            int num1=arr[i-1];
            bool bitSet1=num1&bit;
            if(bitSet1) oneBucket=oneBucket^num1;
            else zeroBucket=zeroBucket^num1;
            int num2=i;
            bool bitSet2=num2&bit;
            if(bitSet2) oneBucket=oneBucket^num2;
            else zeroBucket=zeroBucket^num2;
        }
        
        int missNum=-1,repNum=-1;
        for(int &num:arr){
            if(zeroBucket==num){
                repNum=zeroBucket;
                missNum=oneBucket;
                break;
            }
            else if(oneBucket==num){
                repNum=oneBucket;
                missNum=zeroBucket;
                break;
            }
        }
        return {repNum,missNum};
    }
};

//not suitable for large value of n.
class Solution {
    void cal(int &miss,int &rep,long long sum,long long sumSq,long long n){
        long long Sum=(n*(n+1))/2;
        long long SumOfSq=(n*(n+1)*(2*n+1))/6;
        long long diffNums=sum-Sum;
        long long diffSqNums=sumSq-SumOfSq;
        long long sumNums=diffSqNums/diffNums;
        long long R=(sumNums+diffNums)/2;
        long long M=sumNums-R;
        rep = (int)R;
        miss = (int)M;
    }
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        long long n=arr.size();
        long long sum=0,sumSq=0;
        for(int &num:arr){
            sum+=num;
            sumSq+=1LL*num*num;
        }
        int missNum=-1,repNum=-1;
        cal(missNum,repNum,sum,sumSq,n);
        return {repNum,missNum};
    }
};

int main(){

return 0;
}