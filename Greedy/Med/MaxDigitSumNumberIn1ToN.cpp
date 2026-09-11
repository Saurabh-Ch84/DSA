#include<bits/stdc++.h>
using namespace std;

class Solution {
    int getSumOfDigits(int n){
        int sum=0;
        while(n){
            int d=n%10;
            sum=sum+d;
            n=n/10;
        }
        return sum;
    }
        public:
    int findMax(int n) {
        // code Here
        string upperBound=to_string(n);
        int maxSum=0, N=upperBound.size(), maxi=-1;
        for(int i=0;i<N;i++){
            string temp=upperBound;
            if(upperBound[i]!='0' && i!=N-1){
                temp[i]=upperBound[i]-1;
                for(int j=i+1;j<N;j++)
                    temp[j]='9';
            }
            int newNum=stoi(temp);
            int currSum=getSumOfDigits(newNum);
            if(newNum>n) continue;
            if(currSum>maxSum || (currSum==maxSum && newNum>=maxi)){
                maxi=newNum;
                maxSum=currSum;
            }
        }
        return maxi;
    }
};


int main(){

return 0;
}