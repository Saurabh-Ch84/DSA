#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int &asteroid:asteroids){
            int mass=abs(asteroid);
            bool negative=(asteroid<0)?true:false;
            if(negative){
                while(!s.empty() && s.top()>0 && s.top()<mass) s.pop();
                if(!s.empty() && s.top()==mass){
                    s.pop();
                    continue;
                }
                if(s.empty() || (!s.empty() && s.top()<0)) s.push(asteroid);
            }
            else s.push(asteroid);
        }
        int n=s.size();
        vector<int> resultantAsteroid(n);
        while(n>0){
            resultantAsteroid[n-1]=s.top();
            s.pop();
            n--;
        }
        return resultantAsteroid;
    }
};

int main(){

return 0;
}