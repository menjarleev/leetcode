/*
 * @lc app=leetcode id=1642 lang=cpp
 *
 * [1642] Furthest Building You Can Reach
 */
#include "lc.hpp"

// @lc code=start
class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int m = heights.size();
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i = 0; i < m - 1; i++)
        {
            int diff = heights[i + 1] - heights[i];
            if (diff <= 0)
            {
                continue;
            }
            min_heap.push(diff);
            if (min_heap.size() <= ladders)
            {
                continue;
            }
            bricks -= min_heap.top();
            min_heap.pop();
            if (bricks < 0)
            {
                return i;
            }
        }
        return m - 1;
    }
};
// @lc code=end
