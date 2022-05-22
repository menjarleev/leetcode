/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);
        for(int i = 0; i < n; i ++){
            left_max[i] = i == 0 ? height[i] : max(left_max[i - 1],  height[i]);
        }
        for(int i = n - 1; i >= 0; i --){
            right_max[i] = i == n - 1 ? height[i]: max(right_max[i + 1], height[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};
// @lc code=end

