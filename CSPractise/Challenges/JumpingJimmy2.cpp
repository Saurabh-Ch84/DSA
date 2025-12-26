#include<iostream>
#include<vector>

using namespace std;
using vi = vector<int> ;

// Jumping Jimmy is back, and he's ready to tackle a new tower!
// He has the same goal as before(keep jumping as high as possible until he gets to the top or can't jump any higher),
// but this tower is a little different from the last one - some of the floors can affect Jimmy's jump height!
// More specifically, there are power floors (which increase his jump height by 1),
// and poison floors(which decrease his jump height by 1). The indices of these floors are represented
// by the power and poison arrays.Each index is 0-based, and does not include the initial floor that Jimmy begins on.

// PROBLEM: Given tower(an array representing the gaps between each pair of consecutive floors), as well as power,
// poison, and jumpHeight, your task is to find the height of the highest floor in the tower that
// Jimmy will be able to reach.

// Notes: Both power and poison are sorted in ascending order, with no repeat elements.
//        Elements of power and poison are mutually exclusive - there are no floors that have both attributes.
// Example:
//          For tower = [1, 4, 3, 2, 2, 2, 2, 1, 4, 4, 2, 3, 3, 4, 1, 4, 2, 1, 2, 4, 1, 2, 2, 4, 1],
//          power = [1, 3, 11], poison = [2, 4, 5, 7, 12, 20, 22], and jumpHeight = 4, the output should be
//          jumpingJimmy2(tower, power, poison, jumpHeight) = 56.
//          At first the climb is looking promising for Jimmy, as he lands on some power floors,
//          while avoiding poison floors.But his luck soon runs out, as he then encounters three poison floors,
//          and becomes unable to reach the next floor. The height of the last reachable platform is 56.

int jumpingJimmy2(vi &tower, vi &power, vi& poison, int jumpHeight){
    int n=tower.size(), m=poison.size(), k=power.size();
    int posionIdx=0, powerIdx=0, ptr=0, height=0;
    while(ptr<n){
        if(tower[ptr]>jumpHeight) break;
        height+=tower[ptr];
        if(posionIdx<m && poison[posionIdx]==ptr){
            posionIdx++;
            jumpHeight--;
        }
        if(powerIdx<k && power[powerIdx]==ptr){
            powerIdx++;
            jumpHeight++;
        }
        ptr++;
    }
    return height;
}

int main(){
    vi tower = {1, 4, 3, 2, 2, 2, 2, 1, 4, 4, 2, 3, 3, 4, 1, 4, 2, 1, 2, 4, 1, 2, 2, 4, 1};
    vi power = {1, 3, 11};
    vi poison = {2, 4, 5, 7, 12, 20, 22};
    int jumpHeight = 4;

    cout << jumpingJimmy2(tower, power, poison, jumpHeight) << endl;
return 0;
}