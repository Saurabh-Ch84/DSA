#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    1.Given a string STR and a character K, replace the most frequent character occurring in STR with K.
        Example: If STR is "apple" and K is "z" then the output will be "azzle".

    2.Given an array ARR of size N. Your task is to find and print the number of elements of ARR which are:
        Even numbers and are at the even indices or odd numbers and are at the odd indices.

    3.Given a string containing alphanumeric characters, print the sum of numbers present in the string. 
        Example: STR is "ab3cd67f" then the output is 16.
*/

class Solution{
        public:
    string q1(string str,char k){
        unordered_map<char,int> hashMap;
        int maxF=0,n=str.length();
        for(int i=0;i<n;i++){
            hashMap[str[i]]++;
            maxF=max(maxF,hashMap[str[i]]);
        }
        for(int i=0;i<n;i++){
            if(hashMap[str[i]]==maxF)
                str[i]=k;
        }
        return str;
    }

    void q2(vector<int> &arr,int N){
        int evenCount=0,oddCount=0;
        for(int i=0;i<N;i++){
            if(i%2==0 && arr[i]%2==0) evenCount++;
            if(i%2==1 && arr[i]%2==1) oddCount++;
        }
        cout<<"Number of even Numbers at even Index: "<<evenCount<<endl;
        cout<<"Number of odd Numbers at odd Index: "<<oddCount<<endl;
    }

    int q3(string str){
        int sum=0;
        for(char ch:str){
            if(isdigit(ch))
                sum+=ch-'0';
        }
        return sum;
    }
};

int main(){
    Solution s;

    string str1="Saurabh is here!";
    char k='X';
    cout<<s.q1(str1,k)<<endl;

    vector<int> arr={9,8,3,1,5,3,3,7,3,6};
    s.q2(arr,arr.size());

    string str2="98psy@69c*tIs-edg1";
    cout<<s.q3(str2);
return 0;
}