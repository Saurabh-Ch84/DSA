#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Challenge: Subtract 1 hour from the given time string
string fallback(string time) {
    // 1. Parsing using find/substr is safer and cleaner than manual loops
    int colonPos = time.find(':');
    
    // Extract Hour
    string hourStr = time.substr(0, colonPos);
    
    // Extract Minutes (2 digits after colon)
    string mins = time.substr(colonPos + 1, 2);
    
    // Extract Meridian (last 2 characters)
    string meridian = time.substr(time.length() - 2);

    // 2. The Logic
    if (hourStr == "12") {
        // Going from 12 to 11 implies a meridian swap (Noon -> Morning, Midnight -> Night)
        if (meridian == "AM") meridian = "PM";
        else meridian = "AM";
        
        // Decrement hour (12 becomes 11)
        hourStr = "11"; 
    }
    else if (hourStr == "1") {
        // 1 becomes 12 (Meridian stays the same)
        hourStr = "12";
    }
    else {
        // Standard subtraction (e.g., 4 -> 3)
        int h = stoi(hourStr);
        hourStr = to_string(h - 1);
    }

    return hourStr + ':' + mins + meridian;
}

int main() {
    string time1 = "1:23PM";
    // Expected: "12:23PM"
    cout << "Input: " << time1 << " -> " << fallback(time1) << endl;
      
    string time2 = "4:57AM";
    // Expected: "3:57AM"
    cout << "Input: " << time2 << " -> " << fallback(time2) << endl;    
      
    string time3 = "9:00PM";
    // Expected: "8:00PM"
    cout << "Input: " << time3 << " -> " << fallback(time3) << endl;

    // Edge Case Test: Noon transition
    string time4 = "12:00PM";
    // Expected: "11:00AM"
    cout << "Input: " << time4 << " -> " << fallback(time4) << endl;

    return 0;
}