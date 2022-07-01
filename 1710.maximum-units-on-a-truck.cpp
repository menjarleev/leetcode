/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */
#include "lc.hpp"

// @lc code=start
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){return a[1] > b[1]; };
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int remain = truckSize;
        int ans = 0;
        for(int i = 0; i < boxTypes.size(); i ++){
            int cost = min(remain, boxTypes[i][0]);
            ans += cost * boxTypes[i][1];
            remain -= cost;
            if(remain == 0){
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

