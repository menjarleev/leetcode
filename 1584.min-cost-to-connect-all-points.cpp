/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int m = points.size();
        vector<int> visited(m, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p_q;
        p_q.emplace(0, 0);
        int cost = 0;
        int node_cnt = 0;
        // prim's algorithm implemented by priority queue
        while (node_cnt != m)
        {
            auto p = p_q.top();
            p_q.pop();
            int w = p.first;
            int node = p.second;
            if (!visited[node])
            {
                visited[node] = 1;
                node_cnt++;
                cost += w;
                for (int i = 0; i < m; i++)
                {
                    if (!visited[i])
                    {
                        // manhattan distance
                        int distance = abs(points[i][0] - points[node][0]) + abs(points[i][1] - points[node][1]);
                        p_q.emplace(distance, i);
                    }
                }
            }
        }
        return cost;
    }
};
// @lc code=end
