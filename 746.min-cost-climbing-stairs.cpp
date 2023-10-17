/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */
#include "lc.hpp"

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int prev = cost[0];
        int curr = cost[1];
        for (int i = 2; i < cost.size(); i++)
        {
            int next = min(prev, curr) + cost[i];
            prev = curr;
            curr = next;
        }
        return min(curr, prev);
    }
};
// @lc code=end
