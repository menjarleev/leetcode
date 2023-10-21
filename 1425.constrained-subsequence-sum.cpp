/*
 * @lc app=leetcode id=1425 lang=cpp
 *
 * [1425] Constrained Subsequence Sum
 */

// @lc code=start
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<pair<int, int>> max_queue;
        vector<int> max_total = nums;
        max_queue.push_back({0, nums[0]});
        int max_sum = nums[0];
        for(int j = 1; j < k; ++j){
            max_total[j] = max(max_total[j], max_queue.front().second + nums[j]);
            max_sum = max(max_sum, max_total[j]);
            while(!max_queue.empty() && max_total[j] >= max_queue.back().second){
                max_queue.pop_back();
            }
            max_queue.push_back({j, max_total[j]});
        }
        for(int i = k; i < nums.size(); i ++){
            if(!max_queue.empty()){
                auto [idx, prev_max] = max_queue.front();
                max_total[i] = max(max_total[i], prev_max + nums[i]);
                if(idx == i - k){
                    max_queue.pop_front();
                }
                while(!max_queue.empty() && max_total[i] >= max_queue.back().second){
                    max_queue.pop_back();
                }
            }
            max_sum = max(max_total[i], max_sum);
            max_queue.push_back({i, max_total[i]});
        }
       return max_sum;
    }
};
// @lc code=end

