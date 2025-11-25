#include<iostream>
using namespace std;

class Solution1 {
    void formatter(string s,string& r){
        for(char ch:s)
        {
            if(!('a'<=ch && ch<='z') && !('A'<=ch && ch<='Z') && !('0'<=ch && ch<='9')) 
                continue;
            if('A'<=ch && ch<='Z') ch+='a'-'A';
            r.push_back(ch);
        }
    }
public:
    bool isPalindrome(string s) {
        string res;
        formatter(s,res);
        int left=0,right=res.length()-1;
        while(left<=right)
            if(res[left++]!=res[right--]) 
                return false;
        return true;
    }
};

class Solution2 {
    bool isSame(char a,char b){
        return (a==b || tolower(a)==tolower(b));
    }
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int left=0,right=n-1;
        while(left<right){
            while(left<right && !isalnum(s[left])) left++;
            while(left<right && !isalnum(s[right])) right--;
            if(left<right && !isSame(s[left],s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};

int main(){

return 0;
}