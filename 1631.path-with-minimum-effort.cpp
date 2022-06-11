/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */
#include <vector>
#include <deque>
#include <climits>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    constexpr static int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
        efforts[0][0] = 0;
        deque<pair<int, int>> q;
        q.push_back({0, 0});
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop_front();
            int x = p.first;
            int y = p.second;
            for(int i = 0; i < 4; i ++){
                int tmp_x = x + dir[i][0];
                int tmp_y = y + dir[i][1];
                if(tmp_x >= 0 && tmp_x < m && tmp_y >= 0 && tmp_y < n){
                    // need to be max of the current effort and previous effort
                    int curr_effort = max(abs(heights[tmp_x][tmp_y] - heights[x][y]), efforts[x][y]);
                    if(curr_effort < efforts[tmp_x][tmp_y]){
                        efforts[tmp_x][tmp_y] = curr_effort;
                        q.push_back({tmp_x, tmp_y});
                    }
                }
            }
        }
        return efforts.back().back();
    }
};
// @lc code=end

