#include<bits/stdc++.h>
using namespace std;

/*
            Q1 Integer Break (Easy)
    Problem Statement: Break the number n into two positive integers such that broken numbers sum is equal to the number n, 
    product of the broken numbers is maximum and the numbers have different parity, if it is not possible then return -1.

    Constraints:-
    2 <= n <= 58.

    Example 1:-
    Input: 2
    Output: -1
    Explanation: Since 2 can only be divided into 1(even), 1(even) where both numbers have same parity.

    Example 2:-
    Input: 5
    Output: 6
    Explanation: Since 5 can be divided into 2, 3 where both numbers have different parity.

    Example 3:-
    Input: 3
    Output: 2
    Explanation : Since 3 can be divided into 1, 2 where both numbers have different parity.

*/

int integerBreak1(int n){
    // brute force approach to find the maximum product of two numbers with different parity.
    // impossible for even numbers.
    if(n%2==0) return -1;
    int maxP=0;
    for(int i=1;i<=n;i+=2){
        // try all possibillities.
        maxP=max(maxP,(i*(n-i)));
    }
    return maxP;
}
 
int integerBreak2(int n){
    if(n%2==0) return -1;
    int a=n/2, b=n-a;
    // since n is odd, a and b will have different parity.
    return a*b;
}

/*
    Q2 Anagram Repair (Medium)

    Problem Statement: Given two Strings s and t, calculate minimum total cost of making characters and frequency count of s equal to t.

    Rule:-
        i) For changing a vowel characters of s by using the consonant character of t cost it 1 and vice-versa.
        ii) For changing same character like vowel in s vowel in t the cost is 2 and vice-versa.

    Example 1:- 
    Input: s = "aba" , t = "bab"
    Output: 1
    Explanation: Since a & b characters of s are already equal to t and are present in s & t both therefore, 
    only different character is a (vowel) in s and b (consonant) in t Hence, cost for chaing vowel <-> consonant is 1.

    Example 2:-
    Input: s = "aaa", t = "eee"
    Output: 6
    Explanation: Since None of the characters and there frequency count matches or gets cancelled, both a and e are vowels therefore, 
    for changing one character of a in s equal to e in t it will take cost of 2 Hence, total minimum cost is 6.

    Example 3:-
    Input: s = "hello", t = "world"
    Output: 5
    Explanation: Since t does contain one l and one o therefore we do not need to change one o and one l in s only, 
    h, e, l are needed to be changed by using w, r, d.

*/

bool isVowel(char ch){
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}

int anagramRepairCostWrong(string s,string t){
    // wrong cause it's greedy.
    // sort both strings to make it easier to compare characters.
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    int n=s.length(), cost=0;
    for(int i=0;i<n;i++){
        // if characters are same then continue.
        if(s[i]==t[i]) continue;
        // if characters are different then check for their parity and add cost accordingly.
        bool flag1=isVowel(s[i]), flag2=isVowel(t[i]);
        // if one is vowel and other is consonant then cost is 1 else cost is 2.
        if(flag1^flag2) cost+=1;
        // if both are vowel or both are consonant then cost is 2.
        else cost+=2;
    }
    return cost;
}

int anagramRepairCost(string s,string t){
    int n=s.size();
    vector<int> letters(26,0);
    for(int i=0;i<n;i++){
        int j=t[i]-'a';
        letters[j]--;
    }
    for(int i=0;i<n;i++){
        int j=s[i]-'a';
        letters[j]++;
    }
    int vowelSrc=0, consonantSrc=0; 
    int vowelDest=0, consonantDest=0;
    for(int i=0;i<26;i++){
        if(!letters[i]) continue;
        if(letters[i]>0){
            if(isVowel(i+'a')) vowelSrc+=abs(letters[i]);
            else consonantSrc+=abs(letters[i]);
        }
        else{
            if(isVowel(i+'a')) vowelDest+=abs(letters[i]);
            else consonantDest+=abs(letters[i]);
        }
    }
    int cost=0;
    if(vowelSrc && consonantDest){
        int mini=min(vowelSrc,consonantDest);
        cost+=mini;
        vowelSrc-=mini, consonantDest-=mini;
    }
    if(consonantSrc && vowelDest){
        int mini=min(consonantSrc,vowelDest);
        cost+=mini;
        consonantSrc-=mini, vowelDest-=mini;
    }
    cost=cost+vowelSrc+consonantSrc+vowelDest+consonantDest;
    return cost;
}

int main(){
    cout<<integerBreak2(2)<<endl;
    cout<<integerBreak2(5)<<endl;
    cout<<integerBreak2(3)<<endl;

    cout<<anagramRepairCost("aba","bab")<<endl;
    cout<<anagramRepairCost("aaa","eee")<<endl;
    cout<<anagramRepairCost("hello","world")<<endl;
return 0;
}