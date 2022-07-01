/*
 * @lc app=leetcode id=1354 lang=cpp
 *
 * [1354] Construct Target Array With Multiple Sums
 */
#include "lc.hpp"

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size() == 1){
            return target[0] == 1;
        }
        priority_queue<int, vector<int>, less<int>> pq;
        long long sum = 0;
        for(auto val: target){
            sum += val;
            pq.push(val);
        }
        while(pq.top() > 1){
            int max_val = pq.top();
            sum -= max_val;
            if(sum == 1){
                return true;
            }
            int x = max_val % sum;
            if(x == max_val || x == 0){
                return false;
            }
            sum += x;
            pq.pop();
            pq.push(x);
        }
        return true;
    }
};
// @lc code=end

