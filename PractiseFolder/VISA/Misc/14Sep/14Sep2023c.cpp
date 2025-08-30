#include <iostream>
#include <vector>
using namespace std;

// Step 1: Build the LPS (Longest Prefix Suffix) array
vector<int> buildLPS(string pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0; // length of the previous longest prefix suffix

    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // fallback
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Step 2: Use LPS to search for pattern in text
int KMPsearch(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    if (m == 0) return 0; // empty pattern matches at index 0

    vector<int> lps = buildLPS(pattern);
    int i = 0, j = 0; // i for text, j for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; 
            j++;
            if (j == m) return i - m; // match found
        } else {
            if (j != 0) {
                j = lps[j - 1]; // fallback using LPS
            } else {
                i++;
            }
        }
    }
    return -1; // no match found
}

// Example usage
int main() {
    string s1 = "abxabcabcaby";
    string s2 = "abcaby";
    int index = KMPsearch(s1, s2);
    cout << "First occurrence at index: " << index << endl;
    return 0;
}
