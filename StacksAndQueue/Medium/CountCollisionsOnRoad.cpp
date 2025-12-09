#include<iostream>
#include<stack>
using namespace std;

//Optimal
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int left = 0, right = n - 1;

        // 1. Skip all cars driving away to the left
        while (left < n && directions[left] == 'L') {
            left++;
        }

        // 2. Skip all cars driving away to the right
        while (right >= 0 && directions[right] == 'R') {
            right--;
        }

        // 3. Everything in between collides (unless it's already 'S')
        int count = 0;
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') {
                count++;
            }
        }
        return count;
    }
};

//Brute
class Solution {
public:
    int countCollisions(string directions) {
        stack<char> s;
        int count=0;
        for(char ch: directions){
            if(ch=='R') s.push(ch);
            else if(!s.empty() && ch=='L'){
                if(s.top()=='R'){
                    count+=2;
                    s.pop();
                    while(!s.empty() && s.top()=='R'){
                        s.pop();
                        count+=1;
                    }
                }
                else count+=1;
                s.push('S');
            }
            else if(ch=='S'){
                while(!s.empty() && s.top()=='R'){
                    s.pop();
                    count+=1;
                }
                s.push(ch);
            }
        }
        return count;
    }
};

int main(){

return 0;
}