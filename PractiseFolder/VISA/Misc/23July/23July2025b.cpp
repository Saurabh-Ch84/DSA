#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool hasMoreThanTwoVowels(const string& str) {
    int vowelCount = 0;
    for (char ch : str) {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount++;
            if (vowelCount > 2) return true;
        }
    }
    return false;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile || !outputFile) {
        cerr << "Error opening file.\n";
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (hasMoreThanTwoVowels(line)) {
            outputFile << line << "\n";
        }
    }

    inputFile.close();
    outputFile.close();
    cout << "Filtered strings written to output.txt\n";
    return 0;
}
