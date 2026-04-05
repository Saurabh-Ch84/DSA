#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution1 {
    void addOne(int n,string &result){
        int carry=1, i=n-1;
        while(i>=0 && carry){
             int bit=result[i]-'0';
             result[i]='0'+(carry ^ bit);
             carry=carry & bit;
             i--;
        }
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        string result(n,'0');
        for(int i=0;i<n;i++){
            if(result!=nums[i]) break;
            addOne(n,result);
        }
        return result;
    }
};

class Solution2 {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        unordered_set<int> hashSet;
        for(int &num: arr){
            if(!hashSet.count(num*num))
                hashSet.insert(num*num);
        }
        
        for(auto itrI=hashSet.begin();itrI!=hashSet.end();itrI++){
            int a2=*itrI;
            for(auto itrJ=itrI;itrJ!=hashSet.end();itrJ++){
                int b2=*itrJ;
                if(hashSet.count(a2+b2)) return true;
            }
        }
        return false;
    }
};

int main(){

return 0;
}