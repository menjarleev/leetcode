/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */
#include "lc.hpp"

// @lc code=start
// memo solution
// O(N*D) N -> courses, D -> max_delay
// class Solution {
// public:
//     int schedule(const vector<vector<int>>& courses, vector<vector<int>>& memo, int i, int time){
//         if(i == courses.size()){
//             return 0;
//         }
//         if(memo[i][time] != -1){
//             return memo[i][time];
//         }
//         int taken = 0;
//         if(courses[i][0] + time <= courses[i][1]){
//             taken = 1 + schedule(courses, memo, i + 1, time + courses[i][0]);
//         }
//         int not_taken = schedule(courses, memo, i + 1, time);
//         memo[i][time] = max(taken, not_taken);
//         return memo[i][time];
//     }
//     int scheduleCourse(vector<vector<int>>& courses) {
//         auto cmp = [] (vector<int>& a, vector<int>& b){return a[1] < b[1];};
//         sort(courses.begin(), courses.end(), cmp);
//         int m = courses.size();
//         vector<vector<int>> memo(m, vector<int>(courses.back()[1] + 1, -1));
//         return schedule(courses, memo, 0, 0);
//     }
// };

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        auto cmp = [] (vector<int>& a, vector<int>& b){return a[1] < b[1];};
        sort(courses.begin(), courses.end(), cmp);
        int m = courses.size();
        priority_queue<int, vector<int>, less<int>> pq;
        int time = 0;
        for(const auto& course: courses){
            if(course[0] + time <= course[1]){
                pq.push(course[0]);
                time += course[0];
            }
            // if course has less duration, we squeeze current time
            else if(!pq.empty() && pq.top() > course[0]){
                int prev = pq.top();
                pq.pop();
                time += course[0] - prev;
                pq.push(course[0]);
            }
        }
        return pq.size();
    }
};
// @lc code=end

