#include<iostream>
using namespace std;

class Solution {
    string rightShift(string &res){
        string ans;
        int n=res.length();
        for(int i=0;i<n;i++){
            char alpha=res[i];
            if(alpha=='z') alpha='a';
            else alpha++;
            ans.push_back(alpha);
        }
        return ans;
    }
public:
    char kthCharacter(int k) {
        string word="a";
        while(word.length()<k){
            string res=rightShift(word);
            word += res;
        }
        return word[k-1];
    }
};

int main(){
    Solution s;
    cout<<s.kthCharacter(69);
return 0;
}