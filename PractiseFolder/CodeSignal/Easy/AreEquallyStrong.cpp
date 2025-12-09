#include<iostream>
using namespace std;
/*
💪 Problem: Are Equally Strong

Call two arms equally strong if the heaviest weights they each are able to lift are equal.

Call two people equally strong if:
- Their strongest arms are equally strong (the strongest arm can be either left or right), and
- Their weakest arms are equally strong.

Given your and your friend's arms' lifting capabilities, find out if you two are equally strong.

📘 Example

Input:
yourLeft = 10, yourRight = 15
friendsLeft = 15, friendsRight = 10

Output:
areEquallyStrong(yourLeft, yourRight, friendsLeft, friendsRight) = true

📘 Additional Examples

- yourLeft = 15, yourRight = 10, friendsLeft = 15, friendsRight = 10 → true  
- yourLeft = 15, yourRight = 10, friendsLeft = 10, friendsRight = 15 → true  
- yourLeft = 10, yourRight = 5, friendsLeft = 5, friendsRight = 10 → true  
- yourLeft = 10, yourRight = 5, friendsLeft = 10, friendsRight = 10 → false

📋 Constraints
- 1 ≤ yourLeft, yourRight, friendsLeft, friendsRight ≤ 20
*/

class Solution {
public:
    bool areEquallyStrong(int yourLeft, int yourRight, int friendsLeft, int friendsRight) {
        // TODO: Implement logic to compare strongest and weakest arms
        return (max(yourLeft,yourRight)==max(friendsLeft,friendsRight) && 
                min(yourLeft,yourRight)==min(friendsLeft,friendsRight));
    }
};

int main(){

}