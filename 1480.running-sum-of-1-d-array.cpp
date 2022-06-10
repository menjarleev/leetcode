/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for(int i = 0; i < ans.size(); i ++){
            ans[i] = (i == 0 ? 0 : ans[i - 1]) + nums[i];
        }
        return ans;
    }
};
// @lc code=end

