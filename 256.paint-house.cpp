/*
 * @lc app=leetcode id=256 lang=cpp
 *
 * [256] Paint House
 */
#include "lc.hpp"

// @lc code=start
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int m = costs.size();
        vector<vector<int>> dp(m, vector<int>(3, 0));
        dp[0] = costs[0];
        for(int i = 1; i < m; i ++){
            dp[i][0] = costs[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = costs[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = costs[i][2] + min(dp[i - 1][0], dp[i -  1][1]);
        }
        int ans = min(dp[m - 1][0], min(dp[m - 1][1], dp[m - 1][2]));
        return ans;
    }
};
// @lc code=end

