#include<iostream>
#include<vector>
using namespace std;

class KMP{
    using vint=vector<int>;
        public:
    vint getLPS(string pattern){
        int length=0, m=pattern.length(), i=1;
        vint lps(m,0);
        while(i<m){
            if(pattern[i]==pattern[length]){
                length++;
                lps[i]=length;
                i++;
            }
            else{
                if(length) length=lps[length-1];
                else i++;
            }
        }
        return lps;
    }

    vint findPattern(string pattern,string text){
        int n=text.length(), m=pattern.length();
        int i=0, j=0;
        vint lps=getLPS(pattern), result;
        while(i<n){
            if(j<m && text[i]==pattern[j]){
                i++;
                j++;
                if(j==m) result.push_back(i-j);
            }
            else{
                if(j) j=lps[j-1];
                else i++;
            }
        }
        return result;
    }
};

int main(){
    KMP kmp;
    string text = "aabxaabyaabyaab", pattern = "aabyaab";
    vector<int> matches = kmp.findPattern(pattern, text);
    for(int idx : matches)
        cout << "Pattern found at index: " << idx << endl;
    return 0;
}