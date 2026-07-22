#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0],maxi=0,n=prices.size();
        for(int i=1;i<n;i++){
            mini=min(prices[i],mini);
            maxi=max(maxi,prices[i]-mini);
        }
        return maxi;
    }
};

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int prev=prices[0],n=prices.size();
        prices[0]=0;
        for(int i=1;i<n;i++){
            int temp=prices[i];
            prices[i]=max(prices[i]-prev,prices[i-1]);
            prev=min(prev,temp);
        }
        return prices.back();
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> s;
        int maxi=0;
        for(int &price: prices){
            while(!s.empty() && s.top()>price) s.pop();
            if(s.empty()) s.push(price);
            else maxi=max(maxi,price-s.top());
        }
        return maxi;
    }
};

int main(){

return 0;
}