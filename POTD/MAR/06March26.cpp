#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution1 {
public:
    bool checkOnesSegment(string s) {
        int n=s.length();
        int firstOnes=0, zeros=0;
        for(int i=0;i<n;i++){
            int num=s[i]-'0';
            if(!num) zeros++;
            else if(num && !zeros) firstOnes++;
        }
        return (firstOnes==n-zeros);
    }
};

class Solution2 {
public:
    bool checkOnesSegment(string s) {
        int n=s.length();
        int firstOnes=0, zeros=0;
        for(int i=0;i<n;i++){
            int num=s[i]-'0';
            if(num){
                if(zeros) return false;
                firstOnes++;
            }
            else zeros++;
        }
        return true;
    }
};

class Solution3 {
  public:
    string minWindow(string &s, string &p) {
        // code here
        unordered_map<int,int> hashMap;
        int m=p.length(), n=s.length(), count=0;
        for(int i=0;i<m;i++){
            hashMap[p[i]]--;
        }
        
        int start=-1, minLen=n+1, left=0, right=0;
        while(right<n){
            if(hashMap[s[right]]<0)
                count++;
            hashMap[s[right]]++;
            while(count==m){
                int len=right-left+1;
                if(minLen>len){
                    start=left;
                    minLen=len;
                }
                hashMap[s[left]]--;
                if(hashMap[s[left]]<0)
                    count--;
                else if(!hashMap[s[left]])
                    hashMap.erase(s[left]);
                left++;
            }
            right++;
        }
        
        return (start==-1 ? "": s.substr(start,minLen));
    }
};

int main(){

return 0;
}