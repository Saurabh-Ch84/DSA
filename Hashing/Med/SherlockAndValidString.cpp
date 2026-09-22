#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    int n=s.size();
    vector<int> alphabets(26,0);
    for(int i=0;i<n;i++){
        int j=s[i]-'a';
        alphabets[j]++;
    }
    
    unordered_map<int, int> freqOfFreqMap;
    for(int i=0;i<26;i++){
        if(!alphabets[i]) continue;
        int freq=alphabets[i];
        freqOfFreqMap[freq]++;
    }
    if(freqOfFreqMap.size()==1) return "YES";
    if(freqOfFreqMap.size()>2) return "NO";
    
    auto itr=freqOfFreqMap.begin();
    int freq1=itr->first, count1=itr->second;
    itr++;
    int freq2=itr->first, count2=itr->second;
    
    if((freq2==1 && count2==1) || (freq1==1 && count1==1)) return "YES";
    if((freq2-freq1==1 && count2==1) || (freq1-freq2==1 && count1==1)) return "YES";
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
