#include<iostream>
#include<vector>

using namespace std;
using vi = vector<int> ; 
// Jumping Jimmy is trying to reach the top of a tall tower!

// Given an integer jumpHeight representing the maximum vertical distance he can ascend in one jump,
// and an array tower representing the vertical distances between each floor of the tower,
// your task is to find the total vertical distance Jimmy is able to travel
// (until he reaches the top of the tower or isn't able to complete the next jump).

// Example:
//          For tower = [3, 1, 2] and jumpHeight = 3, the output should be jumpingJimmy(tower, jumpHeight) = 6.
//          After reaching the top of the tower, Jimmy has ascended a total distance of 3 + 1 + 2 = 6.
//
//          For tower = [1, 2, 3, 4] and jumpHeight = 2, the output should be jumpingJimmy(tower, jumpHeight) = 3.
//          Jimmy is able to complete the first two jumps, but he can't clear a gap of size 3,
//          so the total vertical distance is 1 + 2 = 3.
//
//          For tower = [5, 1, 8, 2, 4, 3, 1, 9, 8, 5, 1] and jumpHeight = 1,
//          the output should be jumpingJimmy(tower, jumpHeight) = 0.
//          Jimmy can't even clear the first gap, so he can't ascend the tower at all

int jumpingJimmy(vi &tower,int jumpHeight){
    int height=0;
    for(int & floor: tower){
        if(jumpHeight<floor) break;
        height+=floor;
    }
    return height;
}

int main(){
    vi tower1 = {3, 1, 2};
    cout << "Test 1 (Exp 6): " << jumpingJimmy(tower1, 3) << endl;

    vi tower2 = {1, 2, 3, 4};
    cout << "Test 2 (Exp 3): " << jumpingJimmy(tower2, 2) << endl;

    vi tower3 = {5, 1, 8};
    cout << "Test 3 (Exp 0): " << jumpingJimmy(tower3, 1) << endl;

    return 0;
}