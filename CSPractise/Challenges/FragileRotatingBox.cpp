#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using vi = vector<int> ;
using vs = vector<string> ;

// You need to move a large rectangular box over a rough, hazardous surface. Since you don't have any tools
// to help you move it, your only option is to perform a series of 90 degree rotations (basically just
// repeatedly pushing the box over onto its side).

// Every time you rotate the box, it hits the ground and some damage is done - the amount of damage depends
// on the fragility of the side of the box that it landed on, as well as the roughness of the ground in the
// region where it was dropped.

// More specifically, we calculate the damage by multiplying the box's fragility by the ground's roughness
// for each pair of vertically adjacent cells. So for the box above, dropping it into its current position
// would cause a total of 4*7 + 0*4 + 5*9 = 73 damage.And the next turn will cause 5*7 + 3*0 + 4*7 = 63 damage.

// PROBLEM: Given boxWeakness, an array of strings representing how fragile the box is in each location,
//          and surfaceRoughness, a string of digits representing how damaging each section of the surface is,
//          your task is to find the total amount of damage the box will receive after being rotated across the
//          entire surface

// Note: The length of the surface might not perfectly fit the box; if there's some overhang on the last step,
//       that part won't be damaged.
// Example:
//          For
//          boxWeakness = ["01",
//                         "21",
//                         "10"]
//          and surfaceRoughness = "39513695380152438476", the output should be
//          fragileRotatingBox(boxWeakness, surfaceRoughness) = 56.
//          The total damage is 1*3 + 0*9 + 0*5 + 1*1 + 1*3 + 1*6 +0*9 + 0*5 + 2*3 + 1*8 + 1*0 + 0*1 +
//                                                      0*5 + 1*2 + 1*4 + 1*3 + 0*8 + 0*4 + 2*7 + 1*6 = 56


int fragileRotatingBox(vs &boxWeakness, string surfaceRoughness){
    vector<string> weakness(4);
    int r = boxWeakness.size();
    int c = boxWeakness[0].size();
    
    // 1. Precompute Sides
    for(int i = 0; i < 4; i++){
        if(i % 2 == 0){
            if(i == 0) weakness[i] = boxWeakness[r-1]; // Bottom
            else{
                string temp = boxWeakness[0]; // Top
                reverse(temp.begin(), temp.end());  
                weakness[i] = temp;
            }
        }
        else{
            string temp;
            int k = (i == 1) ? c - 1 : 0; // Right vs Left Col
            for(int j = 0; j < r; j++)
                temp.push_back(boxWeakness[j][k]);
            
            if(k == c - 1) reverse(temp.begin(), temp.end()); // Reverse Right side logic
            weakness[i] = temp;
        }
    }

    int damage = 0; 
    int n = surfaceRoughness.size();
    int ptr = 0, turn = 0;

    // 2. Simulation Loop
    while(ptr < n){
        string weakSide = weakness[turn];
        int k = weakSide.size();
        
        // Loop runs for the length of the current side
        for(int i = 0; i < k; i++){
            // If surface ends mid-side, we stop adding damage (Overhang logic)
            if(ptr >= n) break;
            int sR = surfaceRoughness[ptr] - '0';
            int wS = weakSide[i] - '0';
            damage += wS * sR;
            ptr++;
        }
        // Rotate the box
        turn = (turn + 1) % 4;
    }
    return damage;
}

int main(){
    // Test Case 1: The Example
    vs box1 = {"01", "21", "10"};
    string surface1 = "39513695380152438476";
    cout << "Test 1 (Example): " << fragileRotatingBox(box1, surface1) << " (Expected: 56)" << endl;

    // Test Case 2: Overhang
    // Box Side is 3 chars long, surface is only 2 chars.
    // It should calculate damage for first 2 chars and stop.
    vs box2 = {"000", "000", "222"}; // Bottom side is "222"
    string surface2 = "55";          // Surface is "55"
    // Calc: 2*5 + 2*5 = 20. Third '2' is overhang.
    cout << "Test 2 (Overhang): " << fragileRotatingBox(box2, surface2) << " (Expected: 20)" << endl;

    return 0;
}