#include<bits/stdc++.h>
using namespace std;

class Solution{
    deque<char> dq;
    bool isReversed;
        public:
    Solution(string &s){
        for(const char &letter: s)
            dq.push_back(letter);
        isReversed=0;
    }
    void reverseString(){
        isReversed=1^isReversed;
    }
    void append(int F,char C){
        if(F==1){
            if(isReversed) dq.push_back(C);
            else dq.push_front(C);
        }
        else{
            if(isReversed) dq.push_front(C);
            else dq.push_back(C);
        }
    }
    string getString(){
        string S;
        while(isReversed && !dq.empty()){
            char letter=dq.back();
            dq.pop_back();
            S.push_back(letter);
        }
        while(!isReversed && !dq.empty()){
            char letter=dq.front();
            dq.pop_front();
            S.push_back(letter);
        }
        return S;
    }
};

int main(){
    string S;
    cin>>S;
    int n;
    cin>>n;
    Solution s(S);
    for(int i=0;i<n;i++){
        int T;
        cin>>T;
        if(T==1) s.reverseString();
        else{
            int F;
            cin>>F;
            char C;
            cin>>C;
            s.append(F,C);
        }
    }
    cout<<s.getString();
return 0;
}