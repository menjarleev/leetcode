/*
 * @lc app=leetcode id=505 lang=cpp
 *
 * [505] The Maze II
 */
#include <vector>
#include <queue>
#include <climits>
using namespace std;


// @lc code=start
class Solution {
private:
    class Comparator{
    public:
        bool operator() (vector<int>& a, vector<int>& b){
            return a[2] > b[2];
        }
    };
    const int dir [4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dijkstra(vector<vector<int>>& maze, vector<vector<int>>& dist, vector<int> start){
        priority_queue<vector<int>, vector<vector<int>>, Comparator> p_q;
        p_q.push({start[0], start[1], 0});
        while(!p_q.empty()){
            vector<int> pair = p_q.top();
            p_q.pop();
            // the existing path in the graph is smaller than the one in PQ
            if(dist[pair[0]][pair[1]] < pair[2]){
                continue;
            }
            for(int i = 0; i < 4; i ++){
                int tmp_i = pair[0] + dir[i][0];
                int tmp_j = pair[1] + dir[i][1];
                int cnt = 0;
                while(tmp_i >= 0 && tmp_i < maze.size() && tmp_j >= 0 && tmp_j < maze[0].size() && maze[tmp_i][tmp_j] == 0){
                    tmp_i += dir[i][0];
                    tmp_j += dir[i][1];
                    cnt ++;
                }
                if(dist[pair[0]][pair[1]] + cnt < dist[tmp_i - dir[i][0]][tmp_j - dir[i][1]]){
                    dist[tmp_i - dir[i][0]][tmp_j - dir[i][1]] = dist[pair[0]][pair[1]] + cnt;
                    p_q.push({tmp_i - dir[i][0], tmp_j - dir[i][1], dist[pair[0]][pair[1]] + cnt});
                }
            }
        }
    }
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[start[0]][start[1]] = 0;
        dijkstra(maze, dist, start);
        return dist[destination[0]][destination[1]] == INT_MAX ? -1 : dist[destination[0]][destination[1]];
    }
};
// @lc code=end

