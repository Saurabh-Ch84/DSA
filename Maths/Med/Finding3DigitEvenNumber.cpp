#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> digitFreq(10,0);
        for(int &d: digits)
            digitFreq[d]++;

        vector<int> res;
        for(int i=1;i<10;i++){
            if(!digitFreq[i]) continue;
            digitFreq[i]--;
            for(int j=0;j<10;j++){
                if(!digitFreq[j]) continue;
                digitFreq[j]--;
                for(int k=0;k<10;k+=2){
                    if(!digitFreq[k]) continue;
                    int num=i*100+j*10+k;
                    res.push_back(num);
                }
                digitFreq[j]++;
            }
            digitFreq[i]++;
        }
        return res;
    }
};

int main(){

return 0;
}