#include <bits/stdc++.h>
using namespace std;

string superReducedString(string s) {
     string res;
     for(const char &letter: s){
        if(res.empty() || letter!=res.back())
            res.push_back(letter);
        else res.pop_back();
     }
     return (res.empty()? "Empty String":res);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
