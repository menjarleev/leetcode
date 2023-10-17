/*
 * @lc app=leetcode id=1473 lang=cpp
 *
 * [1473] Paint House III
 */
#include "lc.hpp"

// @lc code=start
class Solution
{
public:
    int memo[100][100][21];
    const int MAX_COST = 1000001;
    int helper(vector<int> &houses, vector<vector<int>> &cost, int target, int curr_index, int curr_neighbor_cnt, int prev_house_color)
    {
        //if current index reaches the end
        if (curr_index == houses.size())
        {
            // if the curr_neighbor_cnt != target -> return an invalid response
            return curr_neighbor_cnt == target ? 0 : MAX_COST;
        }

        if (curr_neighbor_cnt > target)
        {
            return MAX_COST;
        }
        // if it's in memo already
        if (memo[curr_index][curr_neighbor_cnt][prev_house_color] != -1)
        {
            return memo[curr_index][curr_neighbor_cnt][prev_house_color];
        }
        int min_cost = MAX_COST;
        // case where the color is fixed
        if (houses[curr_index])
        {
            int new_neighbor_cnt = curr_neighbor_cnt + (houses[curr_index] != prev_house_color);
            min_cost = helper(houses, cost, target, curr_index + 1, new_neighbor_cnt, houses[curr_index]);
        }
        else
        {
            // iterate over all color to get a minimal
            int total_colors = cost[0].size();
            for (int i = 1; i <= total_colors; i++)
            {
                int new_neighbor_cnt = curr_neighbor_cnt + (i != prev_house_color);
                int curr_cost = cost[curr_index][i - 1] + helper(houses, cost, target, curr_index + 1, new_neighbor_cnt, i);
                min_cost = min(min_cost, curr_cost);
            }
        }
        return memo[curr_index][curr_neighbor_cnt][prev_house_color] = min_cost;
    }
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        memset(memo, -1, sizeof(memo));
        int ans = helper(houses, cost, target, 0, 0, 0);
        return ans == MAX_COST ? -1 : ans;
    }
};
// @lc code=end
