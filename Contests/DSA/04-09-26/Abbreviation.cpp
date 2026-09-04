#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int dp[1001][1001];
 
bool isCapitalLetter(char letter){
    return (letter>='A' && letter<='Z');
}

bool recursion(int i,int j,int n,int m,string &a,string &b){
    if(i==n && j==m) return dp[i][j]=1;
    if(i==n) return dp[i][j]=0;
    if(j==m){
        while(i<n){
            if(isCapitalLetter(a[i]))
                return dp[i][j]=0;
            i++;
        }
        return dp[i][j]=1;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    bool res=0;
    if(!isCapitalLetter(a[i])){
        bool deleteThis=recursion(i+1,j,n,m,a,b), changeThis=0;
        if(!deleteThis && 'A'+a[i]-'a'==b[j]) 
            changeThis=recursion(i+1,j+1,n,m,a,b);
        res=deleteThis|changeThis;
    }
    else if(a[i]==b[j]) res=recursion(i+1,j+1,n,m,a,b);
    return dp[i][j]=res;
}

string abbreviation(string a, string b) {
    int n=a.size(), m=b.size();
    if(n<m) return "NO";
    memset(dp,-1,sizeof(dp));
    bool res=recursion(0,0,n,m,a,b);
    return (res? "YES":"NO");
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
