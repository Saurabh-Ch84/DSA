#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int,int>> v;
        int maxDeadline = 0;
        for(int i = 0; i < deadline.size(); i++) {
            if(deadline[i] > maxDeadline) maxDeadline = deadline[i];
            v.push_back({profit[i], deadline[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int,int>>);
        vector<int> answer(maxDeadline + 1, -1);
        int job = 0, benefit = 0;
        for(int i = 0; i < v.size(); i++) {
            int idx = v[i].second;
            while(idx > 0 && answer[idx] != -1) idx--;
            if(idx > 0) {
                answer[idx] = i;
                job++;
                benefit += v[i].first;
            }
        }
        return {job, benefit};
    }
};

class Solution2 {
    class DSU {
        vector<int> parent;
    public:
        DSU(int n) {
            parent.resize(n + 1);
            for(int i = 0; i <= n; i++) parent[i] = i;
        }
        int Find(int s) {
            if(s == parent[s]) return s;
            return parent[s] = Find(parent[s]);
        }
        void Union(int u, int v) {
            parent[v] = u;
        }
    };
public:
    static bool comp(const pair<int,int> &a, const pair<int,int> &b) {
        return a.first > b.first;
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int,int>> v;
        int maxDeadline = 0;
        for(int i = 0; i < deadline.size(); i++) {
            if(deadline[i] > maxDeadline) maxDeadline = deadline[i];
            v.push_back({profit[i], deadline[i]});
        }
        sort(v.begin(), v.end(), comp);
        DSU d(maxDeadline);
        int job = 0, benefit = 0;
        for(pair<int,int> &p : v) {
            int slot = d.Find(p.second);
            if(slot > 0) {
                d.Union(d.Find(slot - 1), slot);
                job++;
                benefit += p.first;
            }
        }
        return {job, benefit};
    }
};

int main() {
    vector<int> deadline = {2, 1, 2, 1, 3};
    vector<int> profit   = {100, 19, 27, 25, 15};
    Solution1 s1;
    Solution2 s2;
    auto res1 = s1.jobSequencing(deadline, profit);
    auto res2 = s2.jobSequencing(deadline, profit);
    cout << "Naive Greedy: Jobs = " << res1[0] << ", Profit = " << res1[1] << endl;
    cout << "DSU Approach: Jobs = " << res2[0] << ", Profit = " << res2[1] << endl;
    return 0;
}
