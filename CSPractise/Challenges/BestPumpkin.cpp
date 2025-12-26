#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;


// You're looking for the perfect pumpkin to carve into a bold and beautiful jack-o-lantern.
// You've already created a design for how you'd like to carve it, so now it's just a matter of finding a pumpkin that fits!
// The size of the pumpkin isn't very important; it's mostly a matter of getting the right proportions.
// You'd like to pick a pumpkin that has the same aspect ratio as the minimum bounding box of your design.
// If you can't find one that's exactly right, pick the one with the closest aspect ratio.
// You're open to the idea of displaying the pumpkin sideways, so the dimensions can be switched.
// To keep it simple, we'll represent all ratios with the smaller dimension as the numerator (ie: a fraction between 0 and 1).
// Choose the pumpkin whose ratio of dimensions has the smallest absolute difference with the ratio
// of your design's dimensions (represented as fractions between 0 and 1).
// If there's a tie, choose the bigger pumpkin (width * height).
// If there's still a tie, choose the one that appears earlier in the array.
// Your design was drawn on a sheet of A4 paper, then scanned at a very low resolution
// (one pixel per square centimetre), so the resulting image is a 21 x 30 matrix, represented by design,
// an array of strings.Your choices of pumpkins are represented by an array of their dimensions, pumpkinDimensions,
// where each element is of the form[width, height].

// PROBLEM: Given this information, your task is to return the index of the most suitable pumpkin.

// Example: For
//              design = ["..............................",
//                       "..............................",
//                       ".........#....................",
//                       "........##............#.......",
//                       ".......###...........###......",
//                       ".......###..........####......",
//                       "......###...........###.......",
//                       ".....######........######.....",
//                       ".....#######.......#######....",
//                       "..............................",
//                       "...............#..............",
//                       "..............###.............",
//                       ".....#.......#####............",
//                       ".....#....................#...",
//                       ".....##.#................##...",
//                       "......####............#..#....",
//                       "......####..##..###..#####....",
//                       "........#################.....",
//                       ".........###############......",
//                       "...........#..##...##.........",
//                       ".............................."]
//              and pumpkinDimensions = [[14, 22], [9,16], [11,7], [33,23], [42,25]], the output should be
//              bestPumpkin(design, pumpkinDimensions) = 3.
//              The bounding box is 22 by 18 pixels, so we represent it using the fraction 18 / 22, or 9 / 11.
//              Pumpkin 0 has a ratio of 14 / 22, or 7 / 11, so the difference is |9 / 11 - 7 / 11| = 2 / 11.
//              Pumpkin 1 has a ratio of 9 / 16, so the difference is |9 / 11 - 9 / 16| = 45 / 176 (not as close as pumpkin 0).
//              Pumpkin 2 has a ratio of 7 / 11, which gives the same difference as pumpkin 0 (2 / 11),
//              but since this one's smaller, pumpkin 0 is still a better choice.
//              Pumpkin 3 has a ratio of 23 / 33, so the difference is |9 / 11 - 23 / 33| = 4 / 33.
//              Since that's closer than pumpkin 0, this pumpkin is now the best choice.
//              Pumpkin 4 has a ratio of 25 / 42, so the difference is |9 / 11 - 25 / 42| = 103 / 462 (not as close as pumpkin 3).
//              So 3 is the best choice.

int bestPumpkin(vector<string> &design, vector<vector<int>> &pumpkinDimensions){
    int n=design.size(), m=design[0].size();

    int left=m, right=0;
    int top=n, bottom=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(design[i][j]=='#'){
                left=min(left,j);
                right=max(right,j);
                top=min(top,i);
                bottom=max(bottom,i);
            }
        }
    }

    int horizontal=right-left+1;
    int vertical=bottom-top+1;
    double designRatio=(double)min(horizontal,vertical)/(double)max(horizontal,vertical);

    long long area=vertical*horizontal;
    double minDiff=2.0;
    int ansIdx=-1;
    int ptr=0;
    for(vector<int> &dim: pumpkinDimensions){
        int side1=dim[0], side2=dim[1];
        double newRatio=(double)min(side1,side2)/(double)max(side1,side2);
        double diff=abs(newRatio-designRatio);
        if(diff<minDiff){
            ansIdx=ptr;
            minDiff=diff;
            area=side1*side2;
        }
        else if(abs(diff-minDiff)<-1e9){
            long long currentArea=side1*side2;
            if(currentArea>area){
                ansIdx=ptr;
                minDiff=diff;
                area=currentArea;
            }
        }
        ptr++;
    }
    return ansIdx;
}

int main(){
    vector<string> design = {"..............................",
                      "..............................",
                      ".........#....................",
                      "........##............#.......",
                      ".......###...........###......",
                      ".......###..........####......",
                      "......###...........###.......",
                      ".....######........######.....",
                      ".....#######.......#######....",
                      "..............................",
                      "...............#..............",
                      "..............###.............",
                      ".....#.......#####............",
                      ".....#....................#...",
                      ".....##.#................##...",
                      "......####............#..#....",
                      "......####..##..###..#####....",
                      "........#################.....",
                      ".........###############......",
                      "...........#..##...##.........",
                      ".............................."};
return 0;
}