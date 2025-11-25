#include<iostream>
#include<unordered_set>
using namespace std;

/*
    3. First Recurring Character 
        ○ Given a string (e.g., "abaccb"), return the first recurring character. 
        ○ Example: "abaccb" → a
*/

char firstRecurring(string str){
    int n=str.length();
    unordered_set<char> hashSet;
    for(int i=0;i<n;i++){
        if(hashSet.count(str[i]))
            return str[i];
        hashSet.insert(str[i]);
    }
    return '\0'; //not found
}

int main(){
    string str;
    cout<<"Enter string: ";
    cin>>str;
    cout<<firstRecurring(str);
return 0;
}