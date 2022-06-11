/*
 * @lc app=leetcode id=314 lang=cpp
 *
 * [314] Binary Tree Vertical Order Traversal
 */
#include <vector>
#include <unordered_map>
#include <map>
#include <deque>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        unordered_map<int, vector<int>> v_map;
        deque<pair<int, TreeNode*>> q;
        vector<vector<int>> ans;
        if(!root){
            return {};
        }
        // here we keep track of left most index and right most index
        // so that we can get rid of using map
        // which saves us O(logN)
        int left_idx = 0;
        int right_idx = 0;
        q.push_back({0, root});
        while(!q.empty()){
            pair<int, TreeNode*> p = q.front();
            q.pop_front();
            int level = p.first;
            left_idx = min(left_idx, level);
            right_idx = max(right_idx, level);
            TreeNode* node = p.second;
            v_map[level].push_back(node->val);
            if(node->left){
                q.push_back({level - 1, node->left});
            }
            if(node->right){
                q.push_back({level + 1, node->right});
            }
        }
        for(int i = left_idx; i <= right_idx; i ++){
            if(v_map.count(i)){
                ans.push_back(v_map[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

