#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    unordered_set<int> hashSet;
    bool iskthBitSet(int bitMask,int k){
        return ((bitMask>>k) & 1);
    }
    void togglekthBit(int &bitMask,int k){
        bitMask=(bitMask)^(1<<k);
    }
    void recursion(int j,int bitMask,int num,int n,vector<int>& digits){
        if(j==3){
            hashSet.insert(num);
            return ;
        }
        for(int i=0;i<n;i++){
            if(iskthBitSet(bitMask,i)) continue;
            int d=digits[i];
            if(j==0 && d){
                togglekthBit(bitMask,i);
                recursion(j+1,bitMask,num*10+d,n,digits);
                togglekthBit(bitMask,i);
            }
            else if(j==1){
                togglekthBit(bitMask,i);
                recursion(j+1,bitMask,num*10+d,n,digits);
                togglekthBit(bitMask,i);
            }
            else if(j==2 && d%2==0){
                togglekthBit(bitMask,i);
                recursion(j+1,bitMask,num*10+d,n,digits);
                togglekthBit(bitMask,i);
            }
        }
    }
public:
    int totalNumbers(vector<int>& digits) {
        int bitMask=0, n=digits.size();
        recursion(0,bitMask,0,n,digits);
        return hashSet.size();
    }
};

class Solution2 {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> digitFreq(10,0);
        for(int &d: digits)
            digitFreq[d]++;

        int count=0;
        for(int i=1;i<10;i++){
            if(!digitFreq[i]) continue;
            digitFreq[i]--;
            for(int j=0;j<10;j++){
                if(!digitFreq[j]) continue;
                digitFreq[j]--;
                for(int k=0;k<10;k+=2){
                    if(!digitFreq[k]) continue;
                    // int num=i*100+j*10+k;
                    count++;
                }
                digitFreq[j]++;
            }
            digitFreq[i]++;
        }
        return count;
    }
};

int main(){

return 0;
}