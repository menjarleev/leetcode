/*
 * @lc app=leetcode id=1332 lang=cpp
 *
 * [1332] Remove Palindromic Subsequences
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size() == 1) return 1;
        int l = (s.size() - 1) / 2;
        int r = (s.size() % 2 == 0 ? 1 : 0 ) + (s.size() - 1) / 2;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l --;
            r ++;
        }
        return (l == -1 && r == s.size()) ? 1 : 2;
    }
};
// @lc code=end

