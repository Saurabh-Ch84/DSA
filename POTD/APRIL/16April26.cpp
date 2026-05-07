#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
    using vint=vector<int>;
    int minCircularDistance(int n,int i,int j){
        return min((n-i+j)%n,(n+i-j)%n);
    }
public:
    vint solveQueries(vint &nums,vint &queries) {
        int n=nums.size(), q=queries.size();
        unordered_map<int,vint> hashMap;

        for(int i=0;i<n;i++){
            int num=nums[i];
            hashMap[num].push_back(i);
        }

        vint res;
        for(int i=0;i<q;i++){
            int k=queries[i];
            int val=nums[k];
            if(hashMap[val].size()==1)
                res.push_back(-1);
            else{
                vint &values=hashMap[val];
                int m=values.size();

                int j=lower_bound(values.begin(),values.end(),k)-values.begin();
                int leftJ=(j==0 ? values.back(): values[j-1]);
                int rightJ=(j+1==m ? values.front(): values[j+1]);

                int distLeft=minCircularDistance(n,leftJ,k);
                int distRight=minCircularDistance(n,rightJ,k);

                res.push_back(min(distLeft,distRight));
            }
        }
        return res;
    }
};

class Solution {
  public:
    int myAtoi(string &s) {
        // code here
        int n=s.length();
        long long ans=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            char d=s[i];
            if(!isdigit(d)){
                if(d=='-') flag=true;
                continue ;
            }
            ans=(abs(ans*10)+(d-'0'))*(flag? -1:1);
            if(ans>INT_MAX) return INT_MAX;
            if(ans<INT_MIN) return INT_MIN;
        }
        return (int)ans;
    }
};


int main(){

return 0;
}