#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution1{
    void generatePermutations(string s,set<int> &beautifulNumbers) {
        sort(s.begin(), s.end());
        do {
            beautifulNumbers.insert(stoi(s));
        } while (next_permutation(s.begin(), s.end()));
    }

    void precompute(set<int> &beautifulNumbers) {
        vector<string> bases;
        bases.push_back("1");
        bases.push_back("22");
        bases.push_back("122");
        bases.push_back("333");
        bases.push_back("1333");
        bases.push_back("4444");
        bases.push_back("14444");
        bases.push_back("22333");
        bases.push_back("55555");
        bases.push_back("122333");
        bases.push_back("155555");
        bases.push_back("224444");
        bases.push_back("666666");
        bases.push_back("1224444"); // Smallest 7-digit

        for (const string& base : bases)
            generatePermutations(base,beautifulNumbers);
        for(int e:beautifulNumbers)
            cout<<e<<" ";
        cout<<endl;
    }

public:
    int nextBeautifulNumber(int n) {
        set<int> beautifulNumbers;
        precompute(beautifulNumbers);
        auto it = beautifulNumbers.upper_bound(n);
        return (it!=beautifulNumbers.end() ?*it:-1);
    }
};


class Solution2{
    bool isBalanced(int num){
        vector<int> freq(10,0);
        while(num){
            freq[num%10]++;
            num=num/10;
        }
        for(int digit=1;digit<=9;digit++){
            if(freq[digit]!=0 && freq[digit]!=digit) return false;
        }
        return true;
    }

    int recursion(int n,vector<int> &freq,int num,int count){
        if(count==0){
            if(isBalanced(num) && num>n) return num;
            return 0;
        }

        int result=0;
        for(int digit=1;digit<=9;digit++){
            if(freq[digit]>0 && freq[digit]<=count){
                freq[digit]--;
                result=recursion(n,freq,num*10+digit,count-1);
                freq[digit]++;
            }
            if(result) break;
        }
        return result;
    }
public:
    int nextBeautifulNumber(int n) {
        vector<int> freq={0,1,2,3,4,5,6,7,8,9};
        int count=to_string(n).length();
        int result=recursion(n,freq,0,count);
        return (result? result: recursion(n,freq,0,count+1));
    }
};

int main(){
    Solution2 s;
    cout<<s.nextBeautifulNumber(1000);
return 0;
}