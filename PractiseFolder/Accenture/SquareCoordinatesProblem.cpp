#include <iostream>
#include <vector>
#include <cmath>   // for abs()
#include <utility> // for pair

using namespace std;

/*
    Square Coordinates Problem 
        ○ Given two coordinates (x1, y1) and (x2, y2).
        ○ Determine the other two vertices if they form a square with sides parallel to axes.
*/

void findSquareVertices(int x1, int y1, int x2, int y2) {
    // Calculate distances
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);

    // Case 1: Points form a diagonal (dx must equal dy, and cannot be 0)
    if (dx != 0 && dy != 0) {
        if (dx == dy) {
            cout << "Square found (Diagonal Case)!" << endl;
            cout << "Other vertices: (" << x1 << ", " << y2 << ") and (" << x2 << ", " << y1 << ")" << endl;
        } else {
            cout << "-1 (Cannot form a square parallel to axes)" << endl;
        }
    }
    // Case 2: Points form a horizontal side (dy is 0)
    else if (dy == 0 && dx != 0) {
        cout << "Square found (Horizontal Side Case)!" << endl;
        cout << "Option A (Above): (" << x1 << ", " << y1 + dx << ") and (" << x2 << ", " << y2 + dx << ")" << endl;
        cout << "Option B (Below): (" << x1 << ", " << y1 - dx << ") and (" << x2 << ", " << y2 - dx << ")" << endl;
    }
    // Case 3: Points form a vertical side (dx is 0)
    else if (dx == 0 && dy != 0) {
        cout << "Square found (Vertical Side Case)!" << endl;
        cout << "Option A (Right): (" << x1 + dy << ", " << y1 << ") and (" << x2 + dy << ", " << y2 << ")" << endl;
        cout << "Option B (Left):  (" << x1 - dy << ", " << y1 << ") and (" << x2 - dy << ", " << y2 << ")" << endl;
    }
    // Case 4: Same point entered
    else {
        cout << "-1 (Points are identical)" << endl;
    }
}

int main() {
    int x1, y1;
    cout << "Enter x1 and y1: ";
    cin >> x1 >> y1;

    int x2, y2;
    cout << "Enter x2 and y2: ";
    cin >> x2 >> y2;

    findSquareVertices(x1, y1, x2, y2);

    return 0;
}