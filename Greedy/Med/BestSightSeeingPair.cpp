#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    // better solution than brute force, we can use a hash map to store the end scores and their counts. 
    // Then we can iterate through the values and for each value, we can calculate the start score 
    // and check if current score can be maxmised by using maximum valid end score and start score then update the maximum score.
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        map<int,int> hashMap;
        for(int i=0;i<n;i++){
            int endScore=values[i]-i;
            hashMap[endScore]++;
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            int startScore=values[i]+i, endScore=values[i]-i;
            hashMap[endScore]--;
            if(!hashMap[endScore])
                hashMap.erase(endScore);
            if(!hashMap.empty())
                maxi=max(maxi,startScore+hashMap.rbegin()->first);
        }
        return maxi;
    }
};

class Solution2 {
    // better solution, we keep track of the maximum end score seen so far and update the maximum score.
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int> endScoresSuffixMax(n,0);
        for(int i=n-1;i>=0;i--){
            int endScore=values[i]-i;
            endScoresSuffixMax[i]=endScore;
            if(i!=n-1) 
                endScoresSuffixMax[i]=max(endScoresSuffixMax[i],endScoresSuffixMax[i+1]);
        }
        int maxi=0;
        for(int i=0;i<n-1;i++){
            int startScore=values[i]+i;
            maxi=max(maxi,startScore+endScoresSuffixMax[i+1]);
        }
        return maxi;
    }
};

class Solution3 {
    // optimised solution, we keep track of the maximum start score seen so far and update the maximum score.
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size(), maxi=0, maxStartScore=-1e9;
        for(int i=0;i<n;i++){
            int endScore=values[i]-i;
            maxi=max(maxi,maxStartScore+endScore);
            maxStartScore=max(maxStartScore,values[i]+i);
        }
        return maxi;
    }
};

int main(){

return 0;
}