#include<bits/stdc++.h>
using namespace std;

class Solution1 {
    using vint=vector<int>;
public:
    int uniqueXorTriplets(vint &nums) {
        int n=nums.size();
        unordered_set<int> hashSet;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int pairXOR=nums[i]^nums[j];
                if(hashSet.count(pairXOR)) continue;
                hashSet.insert(pairXOR);
            }
        }
        unordered_set<int> tripletSet;
        for(const int &pairXOR: hashSet){
            for(int i=0;i<n;i++){
                int triplet=pairXOR^nums[i];
                if(tripletSet.count(triplet)) continue;
                tripletSet.insert(triplet);
            }
        }
        return tripletSet.size();
    }
};

class Solution2 {
    using vint=vector<int>;
    int maxSizeOfVector(int maxi){
        int t=1;
        while(t<=maxi) 
            t=t<<1;
        return t;
    }
public:
    int uniqueXorTriplets(vint &nums) {
        int n=nums.size(), maxi=*max_element(nums.begin(),nums.end());
        int N=maxSizeOfVector(maxi);
        vint pairXOR(N,0);

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int pairxor=nums[i]^nums[j];
                pairXOR[pairxor]=1;
            }
        }

        vint tripletXOR(N,0);
        int count=0;
        for(int i=0;i<N;i++){
            if(!pairXOR[i]) continue;
            for(int j=0;j<n;j++){
                int triplet=i^nums[j];
                if(!tripletXOR[triplet]) count++;
                tripletXOR[triplet]=1;
            }
        }
        return count;
    }
};

int main(){

return 0;
}