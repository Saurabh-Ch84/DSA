#include<iostream>
#include<vector>
using namespace std;

class Solution {
    using vint=vector<int>;
    class Sieve{
            public:
        int n;
        vint prime;

        Sieve(int n): n(n){
            prime.resize(n,1);
            process();
        }
        void process(){
            prime[0]=prime[1]=0;
            for(long i=2;i<n;i++){
                if(!prime[i]) continue;
                for(long j=i*i;j<n;j+=i)
                    prime[j]=false;
            }
        }
    };
public:
    int minOperations(vector<int>& nums) {
        Sieve s(1e5+30);
        int n=nums.size(), cost=0;
        
        for(int i=0;i<n;i++){
            if((i&1)==0 && !s.prime[nums[i]]){
                int j=1;
                while(!s.prime[nums[i]+j]) j++;
                cost+=j;
            }
            else if(i&1 && s.prime[nums[i]]){
                int j=1;
                while(s.prime[nums[i]+j]) j++;
                cost+=j;
            }
        }
        return cost;
    }
};

int main(){

return 0;
}