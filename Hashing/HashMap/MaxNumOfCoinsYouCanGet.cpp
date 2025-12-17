#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

// Optimal
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n=piles.size(),sum=0;
        for(int i=n/3;i<n;i+=2){
            sum+=piles[i];
        }
        return sum;
    }
};

// Brute
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        map<int,int> mp;
        for(int &pile: piles)
            mp[pile]++;
        
        int sum=0;
        while(!mp.empty()){
            auto last=prev(mp.end());
            int alice=last->first;
            mp[alice]--;
            if(mp[alice]==0){
                mp.erase(last);
                auto newLast=prev(mp.end());
                int myShare=newLast->first;
                sum+=myShare;
                mp[myShare]--;
                if(mp[myShare]==0) mp.erase(newLast);
            }
            else{
                sum+=alice;
                mp[alice]--;
                if(mp[alice]==0) mp.erase(last);
            }
            auto first=mp.begin();
            int bob=first->first;
            mp[bob]--;
            if(mp[bob]==0) mp.erase(first);
        }

        return sum;
    }
};

int main(){

return 0;
}