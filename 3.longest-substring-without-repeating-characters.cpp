/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occur;
        int l = 0, r = 0;
        int ans = 0;
        while(r < s.size()){
            while(!occur.empty() && occur.count(s[r])){
                occur.erase(s[l++]);
            }
            occur.insert(s[r]);
            ans = max(ans, r - l + 1);
            r ++;
        }
        return ans;
    }
};
// @lc code=end

