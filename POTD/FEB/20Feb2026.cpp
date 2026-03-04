#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
    struct Comp{
        bool operator()(const int &a,const int &b) const{
            string A=to_string(a),B=to_string(b);
            return A+B>B+A;
        }
    };
  public:
    string findLargest(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end(), Comp());
        string ans = "";
        for(auto &x : arr){
            ans += to_string(x);
        }
        return ans[0] == '0' ? "0" : ans;
    }
};

class Solution2 {
    string recursion(string s){
        vector<string> specials;
        int sum=0, j=0, n=s.length();
        for(int i=0;i<n;i++){
            sum+=(s[i]=='1'? 1:-1);
            if(!sum){
                string temp=s.substr(j+1,i-j-1);
                specials.push_back("1"+recursion(temp)+"0");
                j=i+1;
            }
        }
        sort(specials.rbegin(),specials.rend());
        string res;
        for(string &special: specials) res+=special;
        return res;
    }
public:
    string makeLargestSpecial(string s) {
        return recursion(s);
    }
};

int main(){

return 0;
}