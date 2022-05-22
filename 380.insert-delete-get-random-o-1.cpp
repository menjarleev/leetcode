/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

#include <vector>
#include <unordered_map>
#include <cstdlib>

using std::vector;
using std::unordered_map;
using std::swap;
using std::rand;

// @lc code=start
class RandomizedSet {
public:
    struct Node{
        int idx;
        int val;
        Node(int idx, int val): idx(idx), val(val){}
    };
    unordered_map<int, Node*> dict;
    vector<Node*> arr;
    RandomizedSet() {
        dict = {};
        arr = {};
    }

    bool insert(int val) {
        if(dict.count(val)){
            return false;
        }
        else{
            Node* node = new Node(arr.size(), val);
            dict[val] = node;
            arr.push_back(node);
            return true;
        }
    }

    bool remove(int val) {
        if(!dict.count(val)){
            return false;
        }
        else{
            Node* node = dict[val];
            if(node->idx != arr.size() - 1){
                arr.back()->idx = node->idx;
                arr[node->idx] = arr.back();
            }
            arr.pop_back();
            dict.erase(val);
            delete node;
            return true;
        }
    }

    int getRandom() {
        Node* node = arr[rand() % arr.size()];
        return node->val;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

