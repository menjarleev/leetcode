/*
 * @lc app=leetcode id=1428 lang=cpp
 *
 * [1428] Leftmost Column with at Least a One
 */
#include <vector>
#include <unordered_set>
using namespace std;
class BinaryMatrix {
  public:
    int get(int row, int col);
    vector<int> dimensions();
};

// @lc code=start
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

//  this binary search is not optimal as the time complexity can reach linear
// class Solution {
// public:
//     int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
//         int m = binaryMatrix.dimensions()[0], n = binaryMatrix.dimensions()[1];
//         vector<unordered_set<int>> valid(2, unordered_set<int>());
//         for(int i = 0; i < m; i ++){
//             valid[0].insert(i);
//             valid[1].insert(i);
//         }
//         int l = 0, r = n - 1;
//         int ans = -1;
//         int idx = 0;
//         while(l <= r){
//             int mid = (r - l) / 2 + l;
//             bool find_one = false;
//             valid[1 - idx & 1].clear();
//             for(auto itr = valid[idx & 1].begin(); itr != valid[idx & 1].end(); itr++){
//                 if(binaryMatrix.get(*itr, mid) == 0){
//                     continue;
//                 }
//                 else{
//                     valid[1 - idx & 1].insert(*itr);
//                     find_one = true;
//                 }
//             }
//             if(find_one){
//                 ans = mid;
//                 r = mid - 1;
//                 idx ++;
//             }
//             else{
//                 l = mid + 1;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int m = binaryMatrix.dimensions()[0], n = binaryMatrix.dimensions()[1];
        int ans = -1;
        int i = 0, j = n - 1;
        while(i < m && j >= 0){
            if(binaryMatrix.get(i, j) == 1){
                ans = j;
                j --;
            }
            else{
                i ++;
            }
        }
        return ans;
    }
};
// @lc code=end

