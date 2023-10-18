/*
 * @lc app=leetcode id=2050 lang=cpp
 *
 * [2050] Parallel Courses III
 */

// @lc code=start
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indegree(n, 0);
        vector<int> outdegree(n, 0);
        unordered_map<int, vector<int>> course_map;
        for(int i = 0; i < relations.size(); i ++){
            indegree[relations[i][1] - 1]++;
            outdegree[relations[i][0] - 1]++;
            course_map[relations[i][0] - 1].push_back(relations[i][1] - 1);
        }
        unordered_set<int> last_courses;
        for(int i = 0; i < n; ++i){
            if(outdegree[i] == 0){
                last_courses.insert(i);
            }
        }
        deque<int> courses_taken;
        vector<int> prerequisite(n, -1);
        for(int i = 0; i < indegree.size(); ++i){
            if(indegree[i] == 0){
                courses_taken.emplace_back(i);
                prerequisite[i] = 0;
            }
        }
        int minimal = -1;
        while(!courses_taken.empty()){
            int course = courses_taken.front();
            courses_taken.pop_front();
            if(last_courses.find(course) != last_courses.end()){
                minimal = max(minimal, prerequisite[course] + time[course]);
            }
            for(const auto& next: course_map[course]){
                prerequisite[next] = max(prerequisite[next], prerequisite[course] + time[course]);
                if(--indegree[next] == 0){
                    courses_taken.push_back(next);
                }
            }
        }
        return minimal;
    }
};
// @lc code=end

