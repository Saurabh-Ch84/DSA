#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isSubFolder(string a,string b){
        int n=a.length(),m=b.length();
        if(n>=m) return false;
        int left=0,right=0;
        while(left<n && right<m){
            if(a[left]==b[right]){
                left++;
                right++;
            }
            else return false;
        }
        return left==n && (b[right]=='/');
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder),end(folder));
        vector<string> ans;
        for(string &folder_:folder){
            if(ans.empty() || !isSubFolder(ans.back(),folder_))
                ans.push_back(folder_);
        }
        return ans;
    }
};

void print(vector<string> folders){
    for(string &folder:folders){
        cout<<folder<<" ";
    }
    cout<<endl;
}

int main(){
    Solution s;
    vector<string> folders={"/a","/a/b/c","/a/d","/c","/x/y/z"};
    print(folders);
    print(s.removeSubfolders(folders));
return 0;
}