/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */
#include <stdlib.h>
#include <vector>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* helper(const vector<vector<int>>& grid, int row_s, int row_e, int col_s, int col_e){
        int val = -1;
        for(int i = row_s; i <= row_e; i ++){
            for(int j = col_s; j <= col_e; j++){
                if(val == -1){
                    val = grid[i][j];
                }
                else{
                    if(grid[i][j] != val){
                        Node* top_left = helper(grid, row_s, (row_s + row_e) / 2, col_s, (col_s + col_e) / 2);
                        Node* top_right = helper(grid, row_s, (row_s + row_e) / 2, (col_s + col_e) / 2 + 1, col_e);
                        Node* btm_left = helper(grid, (row_s + row_e) / 2 + 1, row_e, col_s, (col_s + col_e) / 2);
                        Node* btm_right = helper(grid, (row_s + row_e) / 2 + 1, row_e, (col_s + col_e) / 2 + 1, col_e);
                        Node* n = new Node(1, false, top_left, top_right, btm_left, btm_right);
                        return n;
                    }
                }
            }
        }
        return new Node(val, true);
    }
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, grid.size() - 1, 0, grid[0].size() - 1);
    }
};
// @lc code=end

