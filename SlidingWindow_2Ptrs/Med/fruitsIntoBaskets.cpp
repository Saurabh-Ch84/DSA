#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> fruitMap;
        int left=0,right=0,n=fruits.size(),maxFruits=0;
        while(right<n){
            fruitMap[fruits[right]]++;
            while(fruitMap.size()>2)
            {
                fruitMap[fruits[left]]--;
                if(!fruitMap[fruits[left]]) fruitMap.erase(fruits[left]);
                left++;
            }
            maxFruits=max(maxFruits,right-left+1);
            right++;
        }
        return maxFruits;
    } 
    // more optimal theoritically
    int totalFruit2(vector<int>& fruits) {
        unordered_map<int,int> fruitMap;
        int left=0,right=0,n=fruits.size(),maxFruits=0;
        while(right<n){
            fruitMap[fruits[right]]++;
            if(fruitMap.size()>2)
            {
                fruitMap[fruits[left]]--;
                if(!fruitMap[fruits[left]]) fruitMap.erase(fruits[left]);
                left++;
            }
            if(fruitMap.size()<=2)
                maxFruits=max(maxFruits,right-left+1);
            right++;
        }
        return maxFruits;
    }
};

int main(){

return 0;
}