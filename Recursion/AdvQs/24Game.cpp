#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool recursion(vector<double> &cards,int n){
        if(n==1) return abs(24-cards[0])<=1e-7;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                vector<double> newCards;
                for(int k=0;k<n;k++)
                    if(k!=i && k!=j) newCards.push_back(cards[k]);
                double a=cards[i],b=cards[j];
                vector<double> possibleValues={a+b,a-b,b-a,a*b};
                if(b!=0.0) possibleValues.push_back(a/b);
                if(a!=0.0) possibleValues.push_back(b/a);
                for(double &c:possibleValues){
                    newCards.push_back(c);
                    if(recursion(newCards,newCards.size())) return true;
                    newCards.pop_back();
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> cards_(cards.begin(),cards.end());
        return recursion(cards_,cards_.size());
    }
};

int main(){

return 0;
}