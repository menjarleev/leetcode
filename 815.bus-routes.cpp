/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */
#include <vector>
#include <climits>
#include <algorithm>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// @lc code=start
// This is not going to work as we consider each bus stop as a node
// we should consider each route as a node and do BFS
// class Solution
// {
// public:
//     int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
//     {
//         if(source == target){
//             return 0;
//         }
//         unordered_map<int, unordered_set<int>> stop_to_route_map;
//         unordered_map<int, int> dist;
//         unordered_map<int, int> visited;
//         deque<pair<int, int>> q;
//         for (int i = 0; i < routes.size(); i++)
//         {
//             vector<int> &route = routes[i];
//             for (int j = 0; j < route.size(); j++)
//             {
//                 stop_to_route_map[route[j]].insert(i);
//                 dist[route[j]] = INT_MAX;
//                 visited[route[j]] = 0;
//             }
//         }
//         dist[source] = 0;
//         visited[source] = 1;
//         q.push_back({source, 0});
//         while (!q.empty())
//         {
//             pair<int, int> p = q.front();
//             q.pop_front();
//             int src = p.first;
//             int curr_dist = p.second;
//             for (auto itr = stop_to_route_map[src].begin(); itr != stop_to_route_map[src].end(); itr++)
//             {
//                 for (const int dst : routes[*itr])
//                 {
//                     if (dist[dst] > curr_dist + 1 && !visited[dst])
//                     {
//                         visited[dst] = 1;
//                         dist[dst] = curr_dist + 1;
//                         if (dst == target)
//                         {
//                             return curr_dist + 1;
//                         }
//                         else
//                         {
//                             q.push_back({dst, curr_dist + 1});
//                         }
//                     }
//                 }
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    bool intersect(const vector<int>& route_a, const vector<int>& route_b){
        int i = 0, j = 0;
        while(i < route_a.size() && j < route_b.size()){
            if(route_a[i] == route_b[j]) return true;
            else if(route_a[i] > route_b[j]) j++;
            else i++;
        }
        return false;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target){
            return 0;
        }
        unordered_map<int, vector<int>> g;
        unordered_map<int, int> visited;
        deque<pair<int, int>> q;
        vector<int> targets;
        for(int i = 0; i < routes.size(); i ++){
            sort(routes[i].begin(), routes[i].end());
            const vector<int>& route = routes[i];
            if(binary_search(route.begin(), route.end(), source)){
                visited[i] = 1;
                q.push_back({i, 1});
            }
            if(binary_search(route.begin(), route.end(), target)){
                targets.push_back(i);
            }
        }
        for(int i = 0; i < routes.size(); i ++){
            for(int j = 0; j < i; j ++){
                if(intersect(routes[i], routes[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop_front();
            int route = p.first;
            int dist = p.second;
            if(find(targets.begin(), targets.end(), route) != targets.end()){
                return dist;
            }
            else{
                for(int neighbor: g[route]){
                    if(!visited[neighbor]){
                        visited[neighbor] = 1;
                        q.push_back({neighbor, dist + 1});
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
