#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

class Solution{
    int fun1(int num){
        int count=0;
        for(int i=0;i<32;i++){
            count+=(num & (1<<i))?1:0;
        }
        return count;
    }
    int fun2(int num){
        //Brian Kernighan’s algorithm
        int count=0;
        while(num){
            count++;
            num=num&(num-1);
        }
        return count;
    }

    pair<int,int> fun(int num){
        int firstSetBit=num&(~(num-1));
        firstSetBit= log2(firstSetBit);
        int count=0;
        while(num){
            num=num>>1;
            count++;
        }
        return {firstSetBit,count-1};
    }
        public:
    void getNumberofSetBits(int num){
        cout<<"Total Bits Set: "<<fun2(num)<<endl;
        cout<<"First Set Bit: "<<fun(num).first<<endl;
        cout<<"Last Set Bit: "<<fun(num).second<<endl;
    }
};

int main(){
    Solution s;
    s.getNumberofSetBits(INT32_MAX);
return 0;
}