#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> nums(10,0);
        for(const char &d: secret)
            nums[d-'0']++;
        int n=guess.size(), bulls=0, cows=0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                nums[guess[i]-'0']--;
                bulls++;
            }
        }
        for(int i=0;i<n;i++){
            if(secret[i]!=guess[i] && nums[guess[i]-'0']){
                nums[guess[i]-'0']--;
                cows++;
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};

int main(){

return 0;
}