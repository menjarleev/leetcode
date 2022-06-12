/*
 * @lc app=leetcode id=1786 lang=cpp
 *
 * [1786] Number of Restricted Paths From First to Last Node
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

// @lc code=start
class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> g;
    int MOD = 1000'000'007;
    // the memo is the most important bit
    // we need to get the strict path up to k and the path k + 1 depends on k.
    int DFS(int src, vector<int> &memo, const vector<int> &dist)
    {
        if (src == 0)
        {
            return 1;
        }
        else if (memo[src] != -1)
        {
            return memo[src];
        }
        else
        {
            int sum = 0;
            for (auto itr = g[src].begin(); itr != g[src].end(); itr++)
            {
                int neighbor = itr->first;
                if (dist[neighbor] > dist[src])
                {
                    sum = (sum + DFS(neighbor, memo, dist)) % MOD;
                }
            }
            memo[src] = sum;
            return sum;
        }
    }
    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {
        vector<int> dist(n, INT_MAX);
        for (const auto &edge : edges)
        {
            int ui = edge[0] - 1, vi = edge[1] - 1, wi = edge[2];
            g[ui][vi] = wi;
            g[vi][ui] = wi;
        }
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
        { return a.first > b.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        q.push({0, n - 1});
        dist[n - 1] = 0;
        while (!q.empty())
        {
            pair<int, int> p = q.top();
            q.pop();
            int curr_dist = p.first;
            int node = p.second;
            for (auto itr = g[node].begin(); itr != g[node].end(); itr++)
            {
                int neighbor = itr->first;
                int weight = itr->second;
                if (curr_dist + weight < dist[neighbor])
                {
                    dist[neighbor] = curr_dist + weight;
                    q.push({dist[neighbor], neighbor});
                }
            }
        }
        vector<int> memo(n, -1);
        return DFS(n - 1, memo, dist);
    }
};

// @lc code=end
