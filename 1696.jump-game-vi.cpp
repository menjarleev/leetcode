/*
 * @lc app=leetcode id=1696 lang=cpp
 *
 * [1696] Jump Game VI
 */
#include "lc.hpp"

// @lc code=start
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> score(n, 0);
        score[0] = nums[0];
        deque<int> q;
        q.push_back(0);
        for (int i = 1; i < n; i++)
        {
            // clear old index
            while (!q.empty() && i - k > q.front())
            {
                q.pop_front();
            }
            score[i] = score[q.front()] + nums[i];
            // clear all the scores that is smaller than current score as we always want a larger score to jump from
            while (!q.empty() && score[i] > score[q.back()])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        return score[n - 1];
    }
};
// @lc code=end
