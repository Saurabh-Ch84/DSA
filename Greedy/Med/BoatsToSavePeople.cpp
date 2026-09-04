#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int count=0, n=people.size();
        int left=0, right=n-1;
        while(left<=right){
            if(people[right]+people[left]<=limit) left++;
            right--;
            count++;
        }
        return count;
    }
};

int main(){

return 0;
}