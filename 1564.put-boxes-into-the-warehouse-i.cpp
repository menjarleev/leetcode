/*
 * @lc app=leetcode id=1564 lang=cpp
 *
 * [1564] Put Boxes Into the Warehouse I
 */
#include "lc.hpp"

// @lc code=start
class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int min_height = warehouse[0];
        for(int i = 1; i < warehouse.size(); i ++){
            if(warehouse[i] > min_height){
                warehouse[i] = min_height;
            }
            else{
                min_height = warehouse[i];
            }
        }
        sort(boxes.begin(), boxes.end());
        int cnt = 0;
        int idx = 0;
        for(int i = warehouse.size() - 1; i >= 0; i --){
            if(idx < boxes.size() && boxes[idx] <= warehouse[i]){
                cnt ++;
                idx ++;
            }
        }
        return cnt;
    }
};
// @lc code=end

