#include<iostream>
#include<vector>
using namespace std;

// Given an array of words and a length l, format the text such that each line has exactly l characters
// and is fully justified on both the left and the right. Words should be packed in a greedy approach;
// that is, pack as many words as possible in each line. Add extra spaces when necessary so that
// each line has exactly l characters.

// Extra spaces between words should be distributed as evenly as possible.
// If the number of spaces on a line does not divide evenly between words,
// the empty slots on the left will be assigned more spaces than the slots on the right.
// For the last line of text and lines with one word only, the words should be left justified
// with no extra space inserted between them.

// Example:
//          For
//          words = ["This", "is", "an", "example", "of", "text", "justification."]
//          and l = 16, the output should be

//          textJustification(words, l) = ["This    is    an",
//                                         "example  of text",
//                                         "justification.  "]

void print(vector<string> words){
    for(string &word: words){
        cout<<word<<endl;
    }
    cout<<endl;
}

string justify(vector<string>& words, int left, int right, int eachSpace,
                   int extraSpace, int maxWidth) {
        string line;
        for (int k = left; k < right; k++) {
            line += words[k];
            if (k < right - 1) {
                for (int s = 0; s < eachSpace; s++) line.push_back(' ');
                if (extraSpace > 0) {
                    line.push_back(' ');
                    extraSpace--;
                }
            }
        }
        while (line.length() < maxWidth) line.push_back(' ');
        return line;
    }

vector<string> textJustification(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size(), left = 0;
        while (left < n) {
            int segment = 0, letters = words[left].size();
            int right = left + 1;
            while (right < n && words[right].size() + letters + segment + 1<= maxWidth) {
                letters += words[right].size();
                segment++;
                right++;
            }
            string line;
            if (right == n) {
                line = words[left];
                for (int k = left+1; k < right; k++) {
                    line.push_back(' ');
                    line += words[k];
                }
                while (line.size() < maxWidth) line.push_back(' ');
            } else if (segment == 0) {
                line = words[left];
                while (line.size() < maxWidth) line.push_back(' ');
            } else {
                int remSpaces = maxWidth - letters;
                int eachSpaces = remSpaces / segment;
                int extraSpaces = remSpaces % segment;
                line = justify(words, left, right, eachSpaces, extraSpaces, maxWidth);
            }
            result.push_back(line);
            left = right;
        }
        return result;
    }



int main(){
    vector<string> words={"This","is","an","example","of","text","justification"};
    print(words);
    print(textJustification(words,16));
return 0;
}