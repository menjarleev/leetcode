/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */
#include <vector>
#include <deque>
#include <math.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0, r = 0, ans = 0;
        deque<int> max_q;
        deque<int> min_q;
        while(r != nums.size()){
            while(!min_q.empty() && nums[r] < min_q.back()){
                min_q.pop_back();
            }
            min_q.push_back(nums[r]);
            while(!max_q.empty() && nums[r] > max_q.back()){
                max_q.pop_back();
            }
            max_q.push_back(nums[r]);
            if(abs(max_q.front() - min_q.front()) <= limit){
                ans = max(ans, r - l + 1);
            }
            else{
                while(abs(max_q.front() - min_q.front()) > limit){
                    if(max_q.front() == nums[l]) max_q.pop_front();
                    if(min_q.front() == nums[l]) min_q.pop_front();
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};
// @lc code=end

