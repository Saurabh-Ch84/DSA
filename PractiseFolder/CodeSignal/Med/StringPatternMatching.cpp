#include<iostream>
#include<vector>
using namespace std;

/*
    You are given two strings: pattern and source. The first string pattern contains 
    only the symbols 0 and 1, and the second string source contains only lowercase English letters.

Your task is to calculate the number of substrings of source that match pattern. 

We’ll say that a substring source[l..r] matches pattern if the following three conditions are met:
– The pattern and substring are equal in length.
– Where there is a 0 in the pattern, there is a vowel in the substring. 
– Where there is a 1 in the pattern, there is a consonant in the substring. 

Vowels are ‘a‘, ‘e‘, ‘i‘, ‘o‘, ‘u‘, and ‘y‘. All other letters are consonants.

For pattern = "010" and source = "amazing", the output should be solution(pattern, source) = 2.
– “010” matches source[0..2] = "ama". The pattern specifies “vowel, consonant, vowel”. 
    “ama” matches this pattern: 0 matches a, 1 matches m, and 0 matches a. 
– “010” doesn’t match source[1..3] = "maz" 
– “010” matches source[2..4] = "azi" 
– “010” doesn’t match source[3..5] = "zin" 
– “010” doesn’t match source[4..6] = "ing"

For pattern = "100" and source = "codesignal", the output should be solution(pattern, source) = 0.
– There are no double vowels in the string "codesignal", so it’s not possible for any of its substrings
 to match this pattern.

*/
bool isVowel(char ch){
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='y');
}

int solution(string pattern, string source){
    int n=source.size(),m=pattern.size();
    int count=0;
    for(int i=0;i<(n-m+1);i++){
        bool flag=true;
        int j=i;
        while(j<i+m){
            if(pattern[j-i]=='0' && !isVowel(source[j])){
                flag=false;
                break;
            }
            if(pattern[j-i]=='1' && isVowel(source[j])){
                flag=false;
                break;
            }
            j++;
        }
        if(flag) count++;
    }
    return count;
}

int main(){
    cout<<solution("010","amazing")<<endl;
    cout<<solution("011","amazing")<<endl;
    cout<<solution("100","codesignal")<<endl;
return 0;
}