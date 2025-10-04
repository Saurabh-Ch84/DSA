#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void recursion(vector<int> &arr,vector<string> &res,vector<string> &keyPad,string &temp,int n,int i){
        if(i==n){
            res.push_back(temp);
            return ;
        }
        if(arr[i]==1 || arr[i]==0){
            recursion(arr,res,keyPad,temp,n,i+1);
            return ;
        }
        string str=keyPad[arr[i]];
        int m=str.length();
        for(int j=0;j<m;j++){
            temp.push_back(str[j]);
            recursion(arr,res,keyPad,temp,n,i+1);
            temp.pop_back();
        }
    }
  public:
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<string> res,keyPad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp;
        recursion(arr,res,keyPad,temp,n,0);
        return res;
    }
};

int main(){

return 0;
}