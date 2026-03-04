#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution2 {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(),n.end())-'0';
    }
};

class Solution1 {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n = arr.size(), j= 0;
        for (int i = 0; i < n; i++) {
            // If we find a non-zero element
            if (arr[i]){
                // Swap it with the element at the 'write' pointer
                swap(arr[i], arr[j]);
                // Move the 'write' pointer forward
                j++;
            }
        }
    }
};

int main(){

return 0;
}