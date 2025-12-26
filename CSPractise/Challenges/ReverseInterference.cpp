#include<iostream>
using namespace std;

// Two sets of radio waves were broadcast near each other, with the same wavelength. Both broadcasts are represented
// as strings of uppercase English letters, of equal length.
// Since the two broadcasts may have interfered, some of the letters may have been swapped. There could have also
// been external interference that caused some of the letters to be corrupted.

// You've been called in to investigate the interference, so you've been supplied with some test data.
// Specifically, you're given both of the original broadcasts, as well as both of the received broadcasts,
// and your task is to find the minimum number of swaps required to restore them.

// You may only swap characters of equal index; in other words, broadcastA[i] can be swapped with broadcastB[j] only if i = j.
// If there are multiple consecutive characters that need to be swapped, up to three of them can be done in one move.
// If the original broadcasts can't be restored by a series of swaps, return -1.
// Example: For
//              originalA  = "ABAB"
//              originalB  = "CDCD"
//              broadcastA = "CDAD"
//              broadcastB = "ABCB"

//              the output should be reverseInterference(originalA, originalB, broadcastA, broadcastB) = 2.
//              The characters at indices 0, 1, and 3 have all been swapped. Both 0 and 1 can be swapped back in one move,
//              since they're consecutive characters, not exceeding 3 in a row. After that, one more swap will be needed
//              for character 3, for a total of 2 swaps.

//          For
//              originalA = "ABCDEF"
//              originalB  = "ZYXWVU"
//              broadcastA = "AYXWVU"
//              broadcastB = "ZBCDEF"

//              the output should be reverseInterference(originalA, originalB, broadcastA, broadcastB) = 2.
//              From index 1 to index 5, there are five consecutive characters that need to be swapped.
//              Since there are more than 3 in a row, we'll need to split them up into a group of 3 and a group of 2,
//              so it'll take 2 swaps at least.

//          For
//              originalA = "A"
//              originalB  = "Z"
//              broadcastA = "X"
//              broadcastB = "A"

//              the output should be reverseInterference(originalA, originalB, broadcastA, broadcastB) = -1.
//              Even after swapping the characters, the broadcasts won't match the original, so it's not possible
//              for them to be restored. So we return -1.

int reverseInterference(string originalA, string originalB, string broadcastA, string broadcastB) {
    int n = originalA.size();
    int count = 0;
    
    // New variable: tracks length of the CURRENT consecutive swap chain
    int swapCount = 0; 
    
    int i = 0;
    while (i < n) {
        // If mismatch found
        if (broadcastA[i] != originalA[i] || broadcastB[i] != originalB[i]) {
            
            // Check for valid swap (Corruption check)
            if (broadcastB[i] == originalB[i]) return -1;
            if (broadcastA[i] == originalA[i]) return -1;
            if (broadcastB[i] != originalA[i]) return -1;
            if (broadcastA[i] != originalB[i]) return -1;

            // LOGIC FIX:
            // If we aren't currently swapping (swapCount == 0), start a new move.
            // If we ARE swapping but reached the limit of 3, start a new move.
            if (swapCount == 0 || swapCount == 3) {
                count++;
                swapCount = 1; // Start new chain with this character
            } else {
                swapCount++;   // Continue the existing chain
            }
        } else {
            // Crucial: If we hit a character that DOESN'T need swapping,
            // we must break the current consecutive chain.
            swapCount = 0;
        }
        i++;
    }
    return count;
}

int main() {
    string originalA1  = "ABAB";
    string originalB1  = "CDCD";
    string broadcastA1 = "CDAD";
    string broadcastB1 = "ABCB";
    cout << reverseInterference(originalA1, originalB1, broadcastA1, broadcastB1) << endl;

    string originalA2 = "ABCDEF";
    string originalB2  = "ZYXWVU";
    string broadcastA2 = "AYXWVU";
    string broadcastB2 = "ZBCDEF";
    cout << reverseInterference(originalA2, originalB2, broadcastA2, broadcastB2) << endl;

    string originalA3 = "A";
    string originalB3  = "Z";
    string broadcastA3 = "X";
    string broadcastB3 = "A";
    cout << reverseInterference(originalA3, originalB3, broadcastA3, broadcastB3) << endl;
    return 0;
}