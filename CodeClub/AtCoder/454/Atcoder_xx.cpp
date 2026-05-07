#include<iostream>
#include<vector>
using namespace std;

class Solution{
    string reducer(string &str){
        int n=str.length();
        string res;
        for(int i=0;i<n;i++){
            res.push_back(str[i]);
            if(res.size()>=4 && str[i]==')' && res.substr(res.size()-4)=="(xx)"){
                for(int j=0;j<4;j++) res.pop_back();
                for(int j=0;j<2;j++) res.push_back('x');
            }
        }
        return res;
    }
        public:
    bool solve(string &A,string &B){
        return (reducer(A)==reducer(B));
    }
};

int main(){
    Solution s;
    vector<pair<string, string>> cases = {
        {"(xx)x", "x(xx)"},
        {"(x)x", "(xx)"},
        {")x()x(", ")x()x("},
        {"x", "(x)"},
        {"(((((xx)))))x", "x((((((((((xx))))))))))"},
        {"((xx)xx)xx", "(x((xx))x)(xx)"}
    };
    
    for (auto& p : cases) {
        string A = p.first;
        string B = p.second;
        cout<<s.solve(A,B)<<endl;
    }
return 0;
}