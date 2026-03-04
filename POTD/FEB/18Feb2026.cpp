#include<iostream>
#include<vector>
using namespace std;

class Solution1 {
	string getBinary(int n){
		string binary;
		while(n){
			bool rem=n%2;
			n=n/2;
			binary.push_back(rem+'0');
		}
		return binary;
	}
public:
    bool hasAlternatingBits(int n) {
        string binary=getBinary(n);
        int len=binary.size(), i=0;
        while(i<len-1){
        	bool curr=binary[i]-'0';
        	bool next=binary[i+1]-'0';
        	if(curr==next) return false;
        	i++;
     	}
     	return true;
    }
};

using vi=vector<int>;
class Solution2 {
    int mergeSort(vi &arr,int low,int high){
        if(low>=high) return 0;
        int mid=low+(high-low)/2;
        int left=mergeSort(arr,low,mid);
        int right=mergeSort(arr,mid+1,high);
        int invCount=merge(arr,low,mid,high);
        return left+right+invCount;
    }
    
    int merge(vi &arr,int low,int mid,int high){
        vi temp;
        int left=low, right=mid+1, invCount=0;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left++]);
            }
            else{
                temp.push_back(arr[right++]);
                invCount+=mid-left+1;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left++]);
        }
        while(right<=high){
            temp.push_back(arr[right++]);
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        return invCount;
    }
  public:
    int inversionCount(vi &arr) {
        // Code Here
        return mergeSort(arr,0,arr.size()-1);
    }
};

int main(){

return 0;
}