/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
#include <string>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0){
            return 0;
        }
        stack<pair<char,int>> my_stack;
        int ans = 0;
        for(int i = 0; i < s.size(); i ++){
            if(my_stack.empty()){
                my_stack.emplace(s[i], i);
            }
            else{
                if(s[i] == ')'){
                    if(my_stack.top().first == '('){
                        my_stack.pop();
                        ans = max(ans, my_stack.empty() ? i + 1 : i - my_stack.top().second);
                    }
                    else{
                        my_stack.emplace(s[i], i);
                    }
                }
                else{
                    my_stack.emplace(s[i], i);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

