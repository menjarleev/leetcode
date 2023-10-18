/*
 * @lc app=leetcode id=1361 lang=cpp
 *
 * [1361] Validate Binary Tree Nodes
 */
#include <vector.h>
using namespace std;

// @lc code=start
class Solution {
private:
    bool traverse(int idx, vector<int>& leftChild, vector<int>& rightChild, vector<int>& seen){
        if(seen[idx]){
            return false;
        }
        seen[idx] = 1;
        bool left = true;
        bool right = true;
        if(leftChild[idx] != -1){
            left = traverse(leftChild[idx], leftChild, rightChild, seen);
        }
        if(rightChild[idx] != -1){
            right = traverse(rightChild[idx], leftChild, rightChild, seen);
        }
        return left && right;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> hasParent(n, 0);
        for(const auto& child: leftChild){
            if(child != -1){
                if(hasParent[child] != 0){
                    return false;
                }
                hasParent[child] ++;
            }
        }
        for(const auto& child: rightChild){
            if(child!= -1){
                if(hasParent[child] != 0){
                    return false;
                }
                hasParent[child] ++;
            }
        }
        int sum = std::accumulate(hasParent.begin(), hasParent.end(), 0);
        if(sum != n - 1){
            return false;
        }
        int root = -1;
        for(int i = 0; i < n; ++i){
            if(hasParent[i] == 0){
                root = i;
                break;
            }
        }
        vector<int> seen(n, 0);
        return traverse(root, leftChild, rightChild, seen) && std::accumulate(seen.begin(), seen.end(), 0) == n;
    }
};
// @lc code=end

