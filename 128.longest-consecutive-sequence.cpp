/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */
#include "lc.hpp"

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> dict;
        for(int i = 0; i < nums.size(); i ++){
            dict.insert(nums[i]);
        }
        int ans = 0;
        for(auto itr = dict.begin(); itr != dict.end(); itr ++){
            int val = *itr;
            int tmp_size = 0;
            if(!dict.count(val - 1)){
                while(dict.count(val)){
                    tmp_size ++;
                    val ++;
                }
                ans = max(ans, tmp_size);
            }
        }
        return ans;
    }
};
// @lc code=end

