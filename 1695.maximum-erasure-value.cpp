/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 */
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int sum = 0;
        int ans = 0;
        unordered_set<int> seen;
        while(r < nums.size()){
            while(seen.count(nums[r])){
                sum -= nums[l];
                seen.erase(nums[l++]);
            }
            seen.insert(nums[r]);
            sum += nums[r];
            ans = max(ans, sum);
            r ++;
        }
        return ans;
    }
};
// @lc code=end

