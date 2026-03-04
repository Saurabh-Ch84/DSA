#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution1 {
	string reverse_(string s){
		reverse(s.begin(),s.end());
		return s;
	}
	string invert(string s){
		int n=s.length();
		for(int i=0;i<n;i++)
			s[i]='0'+('1'-s[i]);
		return s;
	}
public:
    char findKthBit(int n, int k) {
        string s="0" ;
        for(int i=1;i<n;i++){
        	s=s+"1"+reverse_(invert(s));
        }
        return s[k-1];
    }
};

class Solution2 {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n=arr.size(), left=0, right=0, maxi=0;
        unordered_map<int,int> hashMap;
        while(right<n){
            hashMap[arr[right]]++;
            while(hashMap.size()>2){
                hashMap[arr[left]]--;
                if(!hashMap[arr[left]])
                    hashMap.erase(arr[left]);
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};

int main(){

return 0;
}