/*
 * @lc app=leetcode id=781 lang=cpp
 *
 * [781] Rabbits in Forest
 */
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> cnt;
        for (auto ans : answers)
        {
            cnt[ans]++;
        }
        int ret = 0;
        for (auto itr = cnt.begin(); itr != cnt.end(); itr++)
        {
            ret += ceil(itr->second / static_cast<double>(itr->first + 1)) * (itr->first + 1);
        }
        return ret;
    }
};
// @lc code=end
