/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */
#include "lc.hpp"

// @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target = nums[nums.size() / 2];
        int ans = 0;
        for(const auto& num: nums){
            ans += abs(num - target);
        }
        return ans;
    }
};
// @lc code=end

