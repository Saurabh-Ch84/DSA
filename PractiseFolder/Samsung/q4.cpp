#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
    Given a string, it consists of only two types of characters 1 and 2. Make a new string by replacing
    every 1 by 11 and two consecutive two to only single No restriction on extra space.
    If the length of the string is increasing use extra space only up to increase in characters
*/

class Solution
{
public:
    string doOperations(string &num)
    {
        int n = num.length();
        int countOnes = 0, consecTwos = 0;
        bool prevIsTwo = false;
        for (char ch : num)
        {
            if (ch == '1')
            {
                countOnes++;
                prevIsTwo = false;
            }
            else
            { // ch == '2'
                if (prevIsTwo)
                {
                    consecTwos++;
                }
                prevIsTwo = true;
            }
        }

        int finalLength = n + countOnes - consecTwos;

        string ans = "";
        bool isPrevTwo = false;
        ans.reserve(finalLength);
        int ptr = 0;
        while (ptr < n)
        {
            if (num[ptr] == '1')
            {
                ans.append(2, '1');
                isPrevTwo = false;
            }
            else{
                if(!isPrevTwo)
                    ans.push_back('2');
                isPrevTwo = true;
            }
            ptr++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string s1="11222";
    string s2="121212";
    cout<<s.doOperations(s1)<<endl;
    cout<<s.doOperations(s2)<<endl;
    return 0;
}