#include<iostream>
using namespace std;

/*
    RGB String Problem 
        ○ Input: n (≤ 50) and a string of length n containing only characters R, G, B. 
        ○ Task: Return the minimum number of changes required so that no two adjacent characters are the same. 
        n = 5   
        String = RRRRR   
        Output = 4  
*/

int minChanges(string &RGBstring){
    int n = RGBstring.length();
    int changes = 0;
    for(int i = 1; i < n; i++){
        if(RGBstring[i] == RGBstring[i-1]) {
            changes++;
            i++; // Skip the next character because we "fixed" the current one
        }
    }
    return changes;
}

int main(){
    string RGBstring;
    cout<<"Enter RGB String: ";
    cin>>RGBstring;
    cout<<minChanges(RGBstring);
return 0;
}