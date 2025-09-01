#include<iostream>
#include<vector>
using namespace std;

class Solution {
    string justifyLine(vector<string>& words, int maxWidth, int left, int right,
                       int eachDashSpace,int extraDashSpace)
    {
        string line;
        for(int i=left;i<right;i++){
            line+=words[i];
            if(i<right-1){
                for(int j=0;j<eachDashSpace;j++){
                    line.push_back(' ');
                }
                if(extraDashSpace>0){
                    line.push_back(' ');
                    extraDashSpace--;
                }
            }
        }
        while(line.length()<maxWidth){
            line.push_back(' ');
        }
        return line;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        int left=0;
        vector<string> result;
        while(left<n){
            int lettersCount=words[left].length();
            int right=left+1,dash=0;
            while(right<n && lettersCount+dash+words[right].length()+1<=maxWidth){
                lettersCount+=words[right].length();
                dash++;
                right++;
            }
            int remDash=maxWidth-lettersCount;
            int eachDashSpace=(dash==0)? 0 : remDash/dash;
            int extraDashSpace=(dash==0)? 0 : remDash%dash;
            if(right==n){
                eachDashSpace=1;
                extraDashSpace=0;
            }
            string line=justifyLine(words,maxWidth,left,right,eachDashSpace,extraDashSpace);
            result.push_back(line);
            left=right;
        }
        return result;
    }
};

void print(vector<string> text){
    for(string &line:text){
        cout<<line<<endl;
    }
    cout<<"\n";
}

int main(){
    Solution s;
    vector<string> text={"Hi","I","am","Saurabh.","I","am","an","Information","Technology","Student."
                            ,"I","am","a","loser.","Lost","everything","that","I","cared","for","one","by"
                        ,"one.","I","hope","that","I","find","peace","someday."};
    int maxWidth=20;
    print(text);
    print(s.fullJustify(text,maxWidth));
return 0;
}