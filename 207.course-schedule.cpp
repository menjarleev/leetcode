/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */
#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> g(numCourses);
        for(const auto& prerequisite: prerequisites){
            int i = prerequisite[0], j = prerequisite[1];
            indegree[i] ++ ;
            g[j].push_back(i);
        }
        deque<int> q;
        for(int i = 0; i < numCourses; i ++){
            if(indegree[i] == 0){
                q.push_back(i);
            }
        }
        while(!q.empty()){
            int i = q.front();
            q.pop_front();
            for(int j: g[i]){
                indegree[j] --;
                if(indegree[j] == 0){
                    q.push_back(j);
                }
            }
        }
        for(int i = 0; i < numCourses; i ++){
            if(indegree[i] != 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

