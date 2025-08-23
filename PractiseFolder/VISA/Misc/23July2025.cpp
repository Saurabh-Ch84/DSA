#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*

You are given an array arr[] of n distinct points in a 2D plane, where each point is represented by its (x, y) 
coordinates.Find the minimum Euclidean distance between two distinct points.

Examples:

Input: arr[] = [[-1, -2], [0, 0], [1, 2], [2, 3]]
Output: 1.414214
Explanation: The smallest distance is between points (1, 2) and (2, 3), which is 1.414214.

Input: arr[] = [[-2, -2], [1, 2], [-1, 0], [3, 3]]
Output: 2.236068
Explanation: The smallest distance is between points (-2, -2) and (-1, 0), which is 2.236068.

*/

class Solution{
    double euclideanDistance(const vector<double> &p,const vector<double> &q){
        // distance formula by Euclidean Distance
        return sqrt(pow(p[0]-q[0],2)+pow(p[1]-q[1],2));
    }

    static bool compX(const vector<double> &p,const vector<double> &q){
        return p[0]<q[0];
    }

    static bool compY(const vector<double> &p,const vector<double> &q){
        return p[1]<q[1];
    }

    double stripClosest(vector<vector<double>> &strip, double minDist){
        //sort strips in y-axis
        sort(strip.begin(), strip.end(), compY);
        //calculate closest pair distance in the strip
        int n = strip.size();
        for(int i = 0; i < n; i++){
            int count = 0;
            // for every point check for only 7 max neighbors according to geometry
            for(int j = i+1; j < n && count < 7; j++){
                if((strip[j][1] - strip[i][1]) >= minDist) break; //no point in going forward as it's sorted
                minDist = min(minDist, euclideanDistance(strip[i], strip[j]));
                count++; //count to break early according to geometry
            }
        }
        return minDist;
    }

    double minDistance(vector<vector<double>>& points, int low, int high) {
        // Base case: brute force for small arrays
        if(high - low + 1 <= 3){
            double minDist = 1e9;
            for(int i = low; i <= high; i++){
                for(int j = i+1; j <= high; j++)
                    minDist = min(minDist, euclideanDistance(points[i], points[j]));
            }
            return minDist;
        }
        // Find midpoint (median)
        int mid = low + (high - low) / 2;
        // Find x coordinate at midpoint
        double midX = points[mid][0];
        // Recursively find minimum in left and right halves
        double distanceLeft = minDistance(points, low, mid);
        double distanceRight = minDistance(points, mid + 1, high);
        double minDist = min(distanceLeft, distanceRight);
        // Create strip of points close to the dividing line
        vector<vector<double>> strip;
        for(int i = low; i <= high; i++){
            if(abs(points[i][0] - midX) < minDist)
                strip.push_back(points[i]);
        }
        // Find closest points in strip
        double stripDist = stripClosest(strip, minDist);
        return min(minDist, stripDist);
    }

public:
    double distanceBetweenClosestPairs(vector<vector<double>> &points){
        int n = points.size();
        sort(points.begin(), points.end(), compX);
        return minDistance(points, 0, n - 1);
    }
};

int main(){
    Solution s;
    vector<vector<double>> nums1={{-1, -2}, {0, 0}, {1, 2}, {2, 3}};
    vector<vector<double>> nums2={{-2, -2}, {1, 2}, {-1, 0}, {3, 3}};
    cout<<s.distanceBetweenClosestPairs(nums1)<<endl;
    cout<<s.distanceBetweenClosestPairs(nums2)<<endl;
return 0;
}