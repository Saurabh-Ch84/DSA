#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int left = 0, right = 0, n = start.size();
        int rooms = 0, minRooms = 0;

        while (left < n && right < n) {
            if (start[left] < end[right]) {
                rooms++;
                left++;
            } else {
                rooms--;
                right++;
            }
            minRooms = max(minRooms, rooms);
        }
        return minRooms;
    }
};


int main(){

return 0;
}