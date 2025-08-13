#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;


class Solution {
  public:
    bool isBalanced(string& k) {
        // code here
        if(k.size()%2==1) return false;
        unordered_map<char,char> hMap;
        hMap['}']='{';
        hMap[')']='(';
        hMap[']']='[';
        
        stack<char> s;
        for(char &ch:k){
            if(s.empty())
            {
                if(hMap.find(ch)!=hMap.end()) return false;
                s.push(ch);
            }
            else{
                if(hMap.find(ch)!=hMap.end() && s.top()==hMap[ch]) 
                    s.pop();
                else s.push(ch);
            }
        }
        return s.empty();
    }
};

int main(){

return 0;
}