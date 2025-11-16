#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0,n=s.length();
        for(int i=0;i<n;i++){
            int one=0,zero=0;
            for(int j=i;j<n;j++){
                if(s[j]=='1') one++;
                else zero++;
                if(one>=zero*zero) count++;
            }
        }
        return count;
    }
};

class Solution2 {
public:
    int numberOfSubstrings(string s) {
        int n=s.length(),count=0;

        vector<int> prefix(n,0);
        prefix[0]=(s[0]=='1')? 1:0;

        for(int i=1;i<n;i++)
            prefix[i]=prefix[i-1]+((s[i]=='1') ? 1:0);

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int ones=prefix[j]-(i>0 ? prefix[i-1]: 0);
                int zeros=(j-i+1)-ones;
                if(zeros*zeros > ones){
                    int wasteIndices=zeros*zeros-ones;
                    j+=wasteIndices-1;
                }
                else if(zeros*zeros==ones)
                    count+=1;
                else{
                    count+=1;
                    int k=sqrt(ones)-zeros;
                    int next=j+k;
                    if(next>=n){
                        count+=(n-j-1);
                        break;
                    }
                    else count+=k;
                    j=next;
                }
            }
        }
        return count;
    }
};

int main(){

return 0;
}