/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:
    // solution use dijkstra
    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //     auto compare = [](vector<int>& a, vector<int>& b){ return a[2] > b[2]; };
    //     vector<unordered_map<int, int>> dist(n);
    //     dist[src][0] = 0;
    //     // vector<int> [idx, k, dist]
    //     priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
    //     pq.push({src, 0, 0});
    //     vector<vector<int>> graph(n, vector<int>(n, -1));
    //     for(const auto& flight: flights){
    //         graph[flight[0]][flight[1]] = flight[2];
    //     }
    //     while(!pq.empty()){
    //         auto p = pq.top();
    //         int idx = p[0];
    //         int num_stop = p[1];
    //         int curr_dist = p[2];
    //         pq.pop();
    //         if(num_stop >= k + 1 || (dist[idx].count(num_stop) && dist[idx][num_stop] < curr_dist)){
    //             continue;
    //         }
    //         for(int i = 0; i < n; i ++){
    //             if(graph[idx][i] != -1){
    //                 int next_dist = curr_dist + graph[idx][i];
    //                 int next_stop = num_stop + 1;
    //                 if(next_stop == k + 1 && i != dst){
    //                     continue;
    //                 }
    //                 if((dist[i].count(next_stop) && dist[i][next_stop] > next_dist) || !dist[i].count(next_stop)){
    //                     dist[i][next_stop] = next_dist;
    //                     pq.push({i, next_stop, next_dist});
    //                 }
    //             }
    //         }
    //     }
    //     int ans = INT_MAX;
    //     for(auto itr = dist[dst].begin(); itr != dist[dst].end(); itr++){
    //         ans = min(ans, itr->second);
    //     }
    //     return ans == INT_MAX ? -1 : ans;
    // }

    // solution use Bellman-Ford
    // time O(KE) space O(V)
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<long>> dist(2, vector<long>(n, INT_MAX));
        dist[0][src] = 0;
        dist[1][src] = 0;
        for(int itr = 0; itr < k + 1; itr ++){
            for(const auto& flight: flights){
                int u = flight[0];
                int v = flight[1];
                int duv = flight[2];
                // prev
                long du = dist[itr & 1][u];
                // curr
                long dv = dist[1 - itr & 1][v];
                if(du + duv < dv){
                    dist[1 - itr & 1][v] = du + duv;
                }
            }
        }
        return dist[1 - k&1][dst] < INT_MAX ? dist[1 - k&1][dst] : -1;
    }
};
// @lc code=end

