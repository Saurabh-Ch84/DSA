#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution1 {
public:
    int binaryGap(int n) {
    	int prev=-1, maxi=0;
    	for(int i=0;i<32;i++){
    		int bit=(n>>i) & 1;
    		if(bit){
    			if(prev!=-1) maxi=max(maxi,i-prev);
    			prev=i;
    		}
    	}
    	return maxi;
    }
};

class Solution2 {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,long> hashMap;
        hashMap[0]++;
        int n=arr.size(), currXOR=0;
        long count=0;
        for(int i=0;i<n;i++){
            currXOR=currXOR^arr[i];
            int compXOR=k^currXOR;
            count+=hashMap[compXOR];
            hashMap[currXOR]++;
        }
        return count;
    }
};

int main(){

return 0;
}