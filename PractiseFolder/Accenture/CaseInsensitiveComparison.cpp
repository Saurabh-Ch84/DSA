#include<iostream>
using namespace std;

/*
    2. Lexicographical String Comparison (Case-Insensitive) 
        ○ Given two strings (with both uppercase & lowercase characters). 
        ○ Ignore case and determine lexicographically smaller string. 
        ○ Return: 
            ■ -1 → if first string is smaller 
            ■ 1 → if second string is smaller 
            ■ 0 → if both are equal
*/

int compare(string a, string b) {
    int n = a.length(), m = b.length();
    int len = min(n, m);
    
    for(int i = 0; i < len; i++) {
        char charA = tolower(a[i]);
        char charB = tolower(b[i]);
        if (charA < charB) return -1;
        if (charA > charB) return 1;
    }
    
    // If one is a prefix of the other (e.g., "apple" and "applepie")
    if (n < m) return -1;
    else if (n > m) return 1;
    
    return 0;
}

int main(){
    string a,b;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    int res=compare(a,b);
    cout<<res;
return 0;
}