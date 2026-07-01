#include<iostream>
#include<vector>
using namespace std;

class Solution1{
public:
    int candy(vector<int>& ratings) {
        int sum=1;
        int i=1;
        int n = ratings.size();
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum++;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down = 1;
            while(i<n && ratings[i]<ratings[i-1]){
                down++;
                sum+=down;
                i++;
            }
            if(down>peak){
                sum+=(down-peak);
            }
        }
        return sum;
    }
};

class Solution2{
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1) return 1;
        vector<int> candy(n, 1);

        // Left to right
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1])
                candy[i] = candy[i-1] + 1;
        }

        // Right to left
        int minCandy=candy[n-1];
        for(int j = n - 2; j >= 0; j--){
            if(ratings[j] > ratings[j+1])
                candy[j] = max(candy[j], candy[j+1] + 1);
            minCandy+=candy[j];
        }
        return minCandy;
    }
};


int main(){

return 0;
}