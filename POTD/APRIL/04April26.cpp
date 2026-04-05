#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    string decimalToBinary(int num,int n){
        string binary;
        while(num){
            int rem=num%2;
            num=num/2;
            binary.push_back(rem+'0');
        }
        
        while(binary.length()!=n) 
            binary.push_back('0');
            
        reverse(binary.begin(),binary.end());
        return binary;
    }
  public:
    vector<string> graycode(int n) {
        // code here
        int m=1<<n;
        vector<string> result;
        for(int i=0;i<m;i++)
            result.push_back(decimalToBinary(i^(i>>1),n));

        return result;
    }
};

class Solution {
    using vchar=vector<char>;
    using vvchar=vector<vchar>;
public:
    string decodeCiphertext(string encodedText, int rows) {
        int m=encodedText.length(), k=m/rows;
        vvchar matrix(rows,vchar(k,'#'));

        int I=0, J=0;
        for(int i=0;i<m;i++){
            matrix[I][J++]=encodedText[i];
            if(J==k){
                I++;
                J=0;
            }    
        }

        string result;
        for(int j=0;j<k;j++){
            int j_=j;
            for(int r=0;r<rows && j_<k;r++){
                result.push_back(matrix[r][j_++]);
            }
        }
        
        while(!result.empty() && result.back()==' ')
            result.pop_back();
        return result;
    }
};

int main(){

return 0;
}