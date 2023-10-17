/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */
#include "lc.hpp"

// @lc code=start
// require sorting
// O(nlogn)
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         vector<pair<int, int>> rating_index_pairs;
//         for(int i = 0; i < ratings.size(); i ++){
//             rating_index_pairs.push_back({ratings[i], i});
//         }
//         sort(rating_index_pairs.begin(), rating_index_pairs.end());
//         vector<int> candles(ratings.size(), 0);
//         int ans = 0;
//         int m = ratings.size();
//         for(int i = 0; i < rating_index_pairs.size(); i ++){
//             int idx = rating_index_pairs[i].second;
//             int val = 1;
//             if(idx - 1 >= 0 && ratings[idx] > ratings[idx - 1]){
//                 val = max(val, candles[idx - 1] + 1);
//             }
//             if(idx + 1 < m && ratings[idx] > ratings[idx + 1]){
//                 val = max(val, candles[idx + 1] + 1);
//             }
//             ans += val;
//             candles[idx] = val;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int candy(vector<int>& ratings) {
        int m = ratings.size();
        vector<int> left(m, 1);
        vector<int> right(m, 1);
        for(int i = 1; i < m; i++){
            if(ratings[i] > ratings[i - 1]){
                left[i] = left[i - 1] + 1;
            }
        }
        for(int i = m - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                right[i] = right[i + 1] + 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i ++){
            ans += max(left[i], right[i]);
        }
        return ans;
    }
};
// @lc code=end

