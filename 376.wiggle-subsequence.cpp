/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */
#include "lc.hpp"

// @lc code=start
class Solution {
public:
    void update(stack<int>& q, vector<int>& nums, bool pos){
        for(int i = 1; i < nums.size(); i ++){
            if(pos && q.top() < nums[i]){
                q.push(nums[i]);
                pos = !pos;
            }
            else if(!pos && q.top() > nums[i]){
                q.push(nums[i]);
                pos = !pos;
            }
            else if(!pos && !q.empty() && q.top() < nums[i]){
                q.pop();
                q.push(nums[i]);
            }
            else if(pos && !q.empty() && q.top() > nums[i]){
                q.pop();
                q.push(nums[i]);
            }
        }
    }
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        if(nums.size() == 2 && nums[1] != nums[0]){
            return 2;
        }
        stack<int> q1;
        q1.push(nums[0]);
        update(q1, nums, true);
        stack<int> q2;
        q2.push(nums[0]);
        update(q2, nums, false);
        int max_size = max(q1.size(), q2.size());
        return max_size;
    }
};
// @lc code=end

