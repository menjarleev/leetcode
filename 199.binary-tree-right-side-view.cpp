/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */
#include "lc.hpp"

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            int size = q.size();
            int val = INT_MAX;
            while(size -- != 0){
                TreeNode* node = q.front();
                q.pop_front();
                val = node->val;
                if(node->left){
                    q.push_back(node->left);
                }
                if(node->right){
                    q.push_back(node->right);
                }
            }
            ans.push_back(val);
        }
        return ans;
    }
};
// @lc code=end

