#include <iostream>
#include <vector>
using namespace std;

/*
### Problem Statement

**Last night you partied a little too hard. Now there's a black and white photo of you that's about to go viral!
You can't let this ruin your reputation, so you want to apply the box blur algorithm to the photo to hide its content.**

The pixels in the input image are represented as integers. The algorithm distorts the input image in the following way:
Every pixel `x` in the output image has a value equal to the **average value** of the pixel values from the **3 × 3
square** that has its center at `x`, including `x` itself.

All the pixels on the border of `x` are then removed.
**Return the blurred image as an integer, with the fractions rounded down.**
---

### Example

For
```
image = [[1, 1, 1],
         [1, 7, 1],
         [1, 1, 1]]
```

the output should be
```
boxBlur(image) = [[1]]
```

To get the value of the middle pixel in the input 3 × 3…

*/

class Solution
{
    bool isValid(int i, int j, int n, int m)
    {
        return (i < n && j < m && i >= 0 && j >= 0);
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> matrix(n - 2, vector<int>(m - 2, 0));

        vector<int> di = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dj = {-1, 0, 1, 1, 1, 0, -1, -1};
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                int val = img[i][j];
                for (int k = 0; k < 8; k++)
                {
                    int i_ = i + di[k];
                    int j_ = j + dj[k];
                    val += img[i_][j_];
                }
                matrix[i - 1][j - 1] = val / 9;
            }
        }
        return matrix;
    }

    void print(vector<vector<int>> nums)
    {
        for (vector<int> &row : nums)
        {
            for (int &num : row)
            {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> image = {
    {7, 4, 0, 1},
    {5, 6, 2, 2},
    {6, 10, 7, 8},
    {1, 4, 2, 0}
    };
    s.print(image);
    s.print(s.imageSmoother(image));
    return 0;
}