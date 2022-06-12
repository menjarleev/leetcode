/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */
#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;

// @lc code=start
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, unordered_map<int, double>> g;
        for(int i = 0; i < edges.size(); i ++){
            int src = edges[i][0];
            int dst = edges[i][1];
            g[src][dst] = succProb[i];
            g[dst][src] = succProb[i];
        }
        vector<double> prob(n, 0);
        prob[start] = 1;
        deque<int> q;
        q.push_back(start);
        while(!q.empty()){
            int node = q.front();
            q.pop_front();
            for(auto itr = g[node].begin(); itr != g[node].end(); itr++){
                int neighbor = itr->first;
                double edge_prob =itr->second;
                double curr_prob = prob[node] * edge_prob;
                if(curr_prob > prob[neighbor]){
                    prob[neighbor] = curr_prob;
                    q.push_back(neighbor);
                }
            }
        }
        return prob[end];
    }
};
// @lc code=end

