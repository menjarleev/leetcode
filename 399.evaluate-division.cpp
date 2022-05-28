/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    double dfs(string curr, string end, unordered_map<string, unordered_map<string, double>>& g, unordered_map<string, int>& visited, double tmp_val){
        if(curr == end){
            return tmp_val;
        }
        for(auto itr = g[curr].begin(); itr != g[curr].end(); itr ++){
            if(!visited[itr->first]){
                visited[itr->first] = 1;
                double val = -1;
                if((val = dfs(itr->first, end, g, visited, tmp_val * itr->second)) > 0){
                    return val;
                }
                visited[itr->first] = 0;
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> g;
        unordered_map<string, int> visited;
        for(int i = 0; i < equations.size(); i++){
            vector<string> eq = equations[i];
            g[eq[0]][eq[1]] = values[i];
            g[eq[1]][eq[0]] = 1 / values[i];
            visited[eq[0]] = 0;
            visited[eq[1]] = 0;
        }
        vector<double> ans;
        for(int i = 0; i < queries.size(); i ++){
            string src = queries[i][0];
            string dst = queries[i][1];
            if(!visited.count(src) || !visited.count(dst)){
                ans.push_back(-1);
                continue;
            }
            auto visited_copy = visited;
            visited_copy[src] = 1;
            double val = dfs(src, dst, g, visited_copy, 1);
            ans.push_back(val);
        }
        return ans;

    }
};
// @lc code=end

