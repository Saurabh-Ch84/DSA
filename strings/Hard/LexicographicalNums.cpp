#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using vi=vector<int>;
using vs=vector<string>;

//brute-force
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vs temp;
        for(int i=1;i<=n;i++)
            temp.push_back(to_string(i));
        sort(temp.begin(),temp.end());
        vi result;
        for(string &num: temp)
            result.push_back(stoi(num));
        return result;
    }
};

//optimal-solution
class Solution {
    void recursion(int d,int n,vi &result){
        if(d>n) return ; 
        result.push_back(d);
        for(int i=0;i<10;i++){
            int j=d*10+i;
            if(j>n) return ;
            recursion(j,n,result);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vi result;
        for(int d=1;d<=min(9,n);d++) 
            recursion(d,n,result);
        return result;
    }
};

int main(){

return 0;
}