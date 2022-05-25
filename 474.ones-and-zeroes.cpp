/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<vector<int>> cnt(k, vector<int>(2, 0));
        for(int i = 0; i < k; i ++){
            int one_cnt = 0;
            int zero_cnt = 0;
            string str = strs[i];
            for(int j = 0; j < str.size(); j ++){
                if(str[j] == '0'){
                    zero_cnt ++;
                }
                else{
                    one_cnt ++;
                }
            }
            cnt[i][0] = zero_cnt;
            cnt[i][1] = one_cnt;
        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < k; i++){
            /**
             * we traverse from right to left, btm to top
             * because if we traverse from left to right, dp with larger index might be affected by the earlier update
             * of smaller index in the same i iteration
            **/
            for(int p = m; p >= cnt[i][0]; p--){
                for(int q = n; q >= cnt[i][1]; q--){
                    dp[p][q] = max(1 + dp[p - cnt[i][0]][q - cnt[i][1]], dp[p][q]);
                }
            }
        }
        return dp.back().back();

    }
};
// @lc code=end

