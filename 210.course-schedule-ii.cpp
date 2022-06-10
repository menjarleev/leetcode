/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */
#include <vector>
#include <deque>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> g(numCourses);
        vector<int> ans;
        for(auto prerequisite: prerequisites){
            int i = prerequisite[0];
            int j = prerequisite[1];
            indegree[i] ++;
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
            ans.push_back(i);
            q.pop_front();
            for(int j: g[i]){
                indegree[j] --;
                if(indegree[j] == 0){
                    q.push_back(j);
                }
            }
        }
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] != 0){
                return {};
            }
        }
        return ans;
    }
};
// @lc code=end

