/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    const int dir [4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void traverse(int i, int j, vector<vector<int>>& visited, vector<vector<char>>& grid){
        visited[i][j] = 1;
        for(int k = 0; k < 4; k ++){
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if(x >= 0 && x < visited.size() && y >= 0 && y < visited[0].size() && !visited[x][y] && grid[x][y] == '1'){
                traverse(x, y, visited, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector(n, 0));
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    traverse(i, j, visited, grid);
                    ans ++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

