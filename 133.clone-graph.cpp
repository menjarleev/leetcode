/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* DFS(Node* ori, unordered_map<Node*, Node*>& mapping){
        if(mapping.count(ori)){
            return mapping[ori];
        }
        else{
            Node* copy = new Node(ori->val);
            mapping[ori] = copy;
            for(Node* neighbor: ori->neighbors){
                copy->neighbors.push_back(DFS(neighbor, mapping));
            }
            return copy;
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        unordered_map<Node*, Node*> mapping;
        Node* copy = DFS(node, mapping);
        return copy;
    }
};
// @lc code=end

