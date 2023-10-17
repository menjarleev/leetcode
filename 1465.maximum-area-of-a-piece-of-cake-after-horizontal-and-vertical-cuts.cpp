/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 */
#include "lc.hpp"

// @lc code=start
class Solution
{
public:
    const int MOD = 1e9 + 7;
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        horizontalCuts.push_back(h);
        horizontalCuts.push_back(0);
        verticalCuts.push_back(w);
        verticalCuts.push_back(0);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int max_h = -1;
        int max_w = -1;
        for (int i = 0; i < horizontalCuts.size() - 1; i++)
        {
            max_h = max(horizontalCuts[i + 1] - horizontalCuts[i], max_h);
        }
        for (int i = 0; i < verticalCuts.size() - 1; i++)
        {
            max_w = max(verticalCuts[i + 1] - verticalCuts[i], max_w);
        }
        return ((long long)max_w * max_h) % MOD;
    }
};
// @lc code=end
