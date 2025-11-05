#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using pli = std::pair<long long, int>;
using FreqMap = std::unordered_map<int, long long>;
using vi = vector<int>;

class Solution{
    struct Comp{
        bool operator()(const pli &a, const pli &b) const{
            if (a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        }
    };
    using TopXSet = std::set<pli>;
    using OthersSet = std::set<pli, Comp>;

    void balanceSets(TopXSet &mainSet, OthersSet &secSet, long long &xSum, int x)
    {
        while (mainSet.size() > x)
        {
            auto itr = mainSet.begin();
            long long freq = itr->first;
            int val = itr->second;

            xSum -= (freq * val);
            secSet.insert({freq, val});
            mainSet.erase(itr);
        }

        while (mainSet.size() < x && !secSet.empty())
        {
            auto itr = secSet.begin();
            long long freq = itr->first;
            int val = itr->second;

            xSum += (freq * val);
            mainSet.insert({freq, val});
            secSet.erase(itr);
        }

        if (!mainSet.empty() && !secSet.empty())
        {
            auto itr1 = mainSet.begin();
            auto itr2 = secSet.begin();

            long long freq1 = itr1->first, val1 = itr1->second;
            long long freq2 = itr2->first, val2 = itr2->second;

            if (freq2 > freq1 || (freq2 == freq1 && val2 > val1))
            {
                mainSet.erase(itr1);
                secSet.erase(itr2);

                mainSet.insert({freq2, val2});
                secSet.insert({freq1, val1});

                xSum -= (freq1 * val1);
                xSum += (freq2 * val2);
            }
        }
    }

    void update(int i, int k, int x, int n, int m, long long &xSum,
                TopXSet &mainSet, OthersSet &secSet,
                FreqMap &freqMap, vi &nums)
    {
        if (i == m - 1)
            return;

        int outGoing = nums[i], inComing = nums[i + k];

        long long outGoingOldFreq = freqMap[outGoing]--;
        pli oldPairOut = {outGoingOldFreq, outGoing};

        if (mainSet.count(oldPairOut)){
            mainSet.erase(oldPairOut);
            xSum -= outGoingOldFreq * outGoing;
        }
        else{
            secSet.erase(oldPairOut);
        }

        if (freqMap[outGoing] > 0){
            mainSet.insert({freqMap[outGoing], outGoing});
            xSum += freqMap[outGoing] * outGoing;
        }

        long long inComingOldFreq = freqMap[inComing]++;
        pli oldPairIn = {inComingOldFreq, inComing};

        if (inComingOldFreq > 0){
            if (mainSet.count(oldPairIn)){
                mainSet.erase(oldPairIn);
                xSum -= inComingOldFreq * inComing;
            }
            else{
                secSet.erase(oldPairIn);
            }
        }

        mainSet.insert({freqMap[inComing], inComing});
        xSum += freqMap[inComing] * inComing;

        balanceSets(mainSet, secSet, xSum, x);
    }

    long long init(int x, TopXSet &mainSet, OthersSet &secSet, FreqMap &freqMap)
    {
        long long xSum = 0;
        for (auto &p : freqMap)
        {
            int val = p.first;
            long long freq = p.second;

            if (mainSet.size() < x){
                mainSet.insert({freq, val});
                xSum += freq * val;
            }
            else{
                auto itr = mainSet.begin();
                long long freq_ = itr->first;
                int val_ = itr->second;

                if (freq_ < freq || (freq_ == freq && val_ < val))
                {
                    mainSet.erase(itr);
                    xSum -= freq_ * val_;
                    secSet.insert({freq_, val_});

                    mainSet.insert({freq, val});
                    xSum += freq * val;
                }
                else{
                    secSet.insert({freq, val});
                }
            }
        }
        return xSum;
    }

public:
    vector<long long> findXSum(std::vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        FreqMap freqMap;
        for (int i = 0; i < k; i++)
            freqMap[nums[i]]++;

        TopXSet mainSet;
        OthersSet secSet;
        long long xSum = init(x, mainSet, secSet, freqMap);

        int m = n - k + 1;
        std::vector<long long> ans(m);
        for (int i = 0; i < m; i++)
        {
            ans[i] = xSum;
            update(i, k, x, n, m, xSum, mainSet, secSet, freqMap, nums);
        }

        return ans;
    }
};

int main()
{

    return 0;
}