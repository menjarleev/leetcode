/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> dict;
        int prefix_sum = 0;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            prefix_sum += nums[i];
            if(prefix_sum == x){
                ans = min(ans, i + 1);
            }
            dict[prefix_sum] = i;
        }
        prefix_sum = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            prefix_sum += nums[i];
            if(prefix_sum == x){
                ans = min((int)nums.size() - i, ans);
            }
            if(dict.count(x - prefix_sum) && dict[x - prefix_sum] < i){
                int op = dict[x - prefix_sum] + 1 + nums.size() - i;
                ans = min(op, ans);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end

