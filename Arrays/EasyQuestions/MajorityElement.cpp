#include<iostream>
#include<vector>
using namespace std;

//Moore-Voting Algorithm
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int majElem=-1,count=0;
        for(int &elem:arr)
        {
            if(count==0)
            {
                majElem=elem;
                count=1;
            }
            else if(majElem==elem) count+=1;
            else count-=1;
        }
        if(count==0) return -1;
        
        int freq=0,n=arr.size();
        for(int i=0;i<n;i++)
            if(arr[i]==majElem) freq++;        
        
        return freq>(n/2)?majElem:-1;
    }
};

int main(){

return 0;
}