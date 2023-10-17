/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */
#include "lc.hpp"

// @lc code=start
class Solution
{
public:
    // create hash function for pair
    class hash_func
    {
    public:
        size_t operator()(const pair<int, int> &p) const
        {
            return p.first ^ p.second;
        }
    };
    unordered_map<pair<int, int>, bool, hash_func> memo;
    bool recursion(int mask, vector<int> &matchsticks, int curr, int target, int side_formed)
    {
        if (side_formed == 3)
        {
            return true;
        }
        pair<int, int> key = {mask, side_formed};
        // use memo to avoid duplicate case
        if (memo.count(key))
        {
            return memo[key];
        }
        if (curr == target)
        {
            side_formed++;
            curr = 0;
        }
        bool ans = false;
        for (int i = matchsticks.size() - 1; i >= 0; i--)
        werfafaksfj\\\\\\\\\\\hdfgdklgjsdflkgjdfslkjgldfksgjldf dsha
f8iouaweb w ufgaszbdwsai fu8cnfv wsi vsdznb osedidvbasnmoxzi sauszhd vdszfbawsnbfksdv fnsadf   jds{
            if ((mask & (1 << i)) == 0 || curr + matchsticks[i] > target)
                continue;
            if (recursion(mask ^ (1 << i), matchsticks, curr + matchsticks[i], target, side_formed))
            {
                ans = true;
                break;
            }
        }
        memo[key] = ans;
        return ans;
    }
    bool makesquare(vector<int> &matchsticks)
    {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0)
        {
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end());
        int side_length = sum / 4;
        int n = matchsticks.size();
        return recursion((1 << n) - 1, matchsticks, 0, side_length, 0);
    }
};
// @lc code=end
