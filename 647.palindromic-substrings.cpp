/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
private:
    void get_substring_len(string s, int l, int r, int& ans){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
            ans ++;
        }
    }
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i ++){
            get_substring_len(s, i, i, ans);
            get_substring_len(s, i, i + 1, ans);
        }
        return ans;
    }
};
// @lc code=end

