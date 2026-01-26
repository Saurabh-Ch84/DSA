#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<climits>

using namespace std;
using vi = vector<int>;
using vb = vector<bool>;

class Solution{
    void sieve(int maxi,unordered_map<int,int> &hashMap){
        vb isPrime(maxi+1,true);
        isPrime[0]=false, isPrime[1]=false;
        vi primes;

        for(long long i=2;i<=maxi;i++){
            if(isPrime[i]){
                primes.push_back(i);
                for(long long j=i*i;j<=maxi;j+=i){
                    isPrime[j]=false;
                }
            }
        }

        for(int &p: primes){
            long long cube=1LL*(p*p*p);
            if(cube<=maxi){
                hashMap[cube]=1+(p)+(p*p)+cube;
            }
        }

        int n=primes.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long prod=1LL*(primes[i]*primes[j]);
                if(prod<=maxi){
                    hashMap[prod]=1+primes[i]+primes[j]+prod;
                }
            }
        }

    }
        public:
    int sumFourDivisors(vector<int> &nums){
        int maxi=*max_element(nums.begin(),nums.end());
        unordered_map<int,int> hashMap;
        sieve(maxi,hashMap);
        long long sum=0;
        for(int &num: nums){
            if(hashMap.count(num)){
                sum+=hashMap[num];
            }
        }
        return (int)sum;
    }
};

int main(){
    Solution s;
    vi nums={21,3,7,1};
    cout<<s.sumFourDivisors(nums);
return 0;
}