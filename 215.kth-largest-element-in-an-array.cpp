/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
#include "lc.hpp"

// @lc code=start
class Solution {
public:
    int partition(vector<int>& nums, int l, int r){
        int pivot = nums[l];
        int i = l, j = r;
        while(i < j){
            while(i < j && nums[j] >= pivot){
                j --;
            }
            while(i < j && nums[i] <= pivot){
                i ++;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[l]);
        return i;
    }
    int quick_select(vector<int>& nums, int l, int r, int k){
        int pivot_index = partition(nums, l, r);
        if(k == pivot_index){
            return nums[k];
        }
        if(k > pivot_index){
            return quick_select(nums, pivot_index + 1, r, k);
        }
        else{
            return quick_select(nums, l, pivot_index - 1, k);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int k_smallest = nums.size() - k;
        return quick_select(nums, 0, nums.size() - 1, k_smallest);
    }
};
// @lc code=end

