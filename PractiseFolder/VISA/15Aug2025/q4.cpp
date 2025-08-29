#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Better Approach
    vector<int> findMaxGuests2(int Entry[], int Exit[], int N)
    {
        // Your code goes here
        vector<pair<int, int>> guest;
        for (int i = 0; i < N; i++)
        {
            int entryG = Entry[i], exitG = Exit[i];
            guest.push_back({entryG, exitG});
        }
        sort(guest.begin(), guest.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int minTime = -1;
        for (auto &p : guest)
        {
            int currArr = p.first, currDept = p.second;
            int sz = pq.size();
            if (!pq.empty() && pq.top() < currArr)
                pq.pop();

            pq.push(currDept);
            if (pq.size() > sz)
                minTime = currArr;
        }
        return {(int)pq.size(), minTime};
    }

    //Optimal Approach
    vector<int> findMaxGuests2(int Entry[], int Exit[], int N)
    {
        // Your code goes here
        sort(Entry, Entry + N);
        sort(Exit, Exit + N);

        int arrPtr = 0, deptPtr = 0, guest = 0;
        int maxGuest = 0, timeOfMeet = 0;
        while (arrPtr < N && deptPtr < N)
        {
            int arrTime = Entry[arrPtr];
            int deptTime = Exit[deptPtr];
            if (arrTime <= deptTime)
            {
                guest++;
                if (maxGuest < guest)
                {
                    maxGuest = guest;
                    timeOfMeet = arrTime;
                }
                arrPtr++;
            }
            else
            {
                guest--;
                deptPtr++;
            }
        }
        return {maxGuest, timeOfMeet};
    }
    
};

int main()
{

    return 0;
}