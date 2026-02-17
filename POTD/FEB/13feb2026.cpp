#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution1 {
    int getCase1(int n,string &s){
        int len=0, left=0, right=0;
        while(right<n){
            while(left<right && s[left]!=s[right])
                left++;
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }

    int getCase2(int n,string &s,char ch1,char ch2){
        int len=0, ptr=0, count1=0, count2=0;
        unordered_map<int,int> hashMap; //diff,idx
        while(ptr<n){
            char ch=s[ptr];
            if(ch==ch1) count1++;
            else if(ch==ch2) count2++;
            else{
                hashMap.clear();
                count1=0;
                count2=0;
            }
            if(count1==count2) len=max(len,count1*2);
            int diff=count1-count2;
            if(hashMap.count(diff)) len=max(len,ptr-hashMap[diff]);
            else hashMap[diff]=ptr;
            ptr++;
        }
        return len;
    }

    int getCase3(int n,string &s,char ch1='a',char ch2='b',char ch3='c'){
        int len=0, ptr=0, count1=0, count2=0, count3=0;
        unordered_map<string,int> hashMap; //diff_diff,indx
        while(ptr<n){
            char ch=s[ptr];
            if(ch==ch1) count1++;
            else if(ch==ch2) count2++;
            else count3++;
            if(count1==count2 && count1==count3) len=max(len,count1*3);
            int diff1=count1-count2, diff2=count1-count3;
            string key=to_string(diff1)+'_'+to_string(diff2);
            if(hashMap.count(key)) len=max(len,ptr-hashMap[key]);
            else hashMap[key]=ptr;
            ptr++;
        }
        return len;
    }
public:
    int longestBalanced(string s) {
        int n=s.length(), maxi=0;
        // Case-1
        int maxiCase1=getCase1(n,s);
        // Case-2
        int maxiCase2=max({ getCase2(n,s,'a','b'),
                            getCase2(n,s,'b','c'),
                            getCase2(n,s,'c','a') });
        // Case-3
        int maxiCase3=getCase3(n,s);
        return max({maxiCase1,maxiCase2,maxiCase3});
    }
};


class Solution2 {
    bool check(int mid,int d){
        int num=mid, sum=0;
        while(num){
            int d=num%10;
            sum+=d;
            num=num/10;
        }
        return (mid-sum)>=d;
    }
  public:
    int getCount(int n, int d) {
        // code here
        int low=1, high=n;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool resp=check(mid,d);
            if(resp){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return (ans? n-ans+1: 0);
    }
};


int main(){

return 0;
}