#include<iostream>
using namespace std;

class Solution{
    bool isAlphaNumberic(char letter){
        return (isdigit(letter) || isalpha(letter));
    }

    bool isVowel(char letter){
        letter=tolower(letter);
        return (letter=='a' || letter=='e' || letter=='i' || letter=='o' || letter=='u');
    }

    bool isConsonant(char letter){
        return (isalpha(letter) && !isVowel(letter));
    }
public:
    bool isValid(string word) {
        int n=word.length();
        if(n<3) return false;

        int vowelCount=0,consoCount=0;
        for(int i=0;i<n;i++){
            if(!isAlphaNumberic(word[i]))
                return false;
            if(isVowel(word[i]))
                vowelCount++;
            else if(isConsonant(word[i]))
                consoCount++;
        }
        return (vowelCount>=1 && consoCount>=1);
    }
};

int main(){
    Solution s;
    cout<<s.isValid("Saurabh84and^9");
return 0;
}