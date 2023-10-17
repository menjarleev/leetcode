/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */
#include "lc.hpp"

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1, col = 0;
        while(row >= 0 && col < matrix[0].size()){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                col ++;
            }
            else{
                row --;
            }
        }
        return false;
    }
};
// @lc code=end

