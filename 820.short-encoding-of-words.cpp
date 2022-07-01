/*
 * @lc app=leetcode id=820 lang=cpp
 *
 * [820] Short Encoding of Words
 */
#include "lc.hpp"

// @lc code=start
class Solution {
public:
    class Rev_Trie{
        struct Node{
            char val;
            unordered_map<char, Node*> children;
            Node(char c='\0'): val(c){}
        };
        Node* root;

        public:
            Rev_Trie(){
                root = new Node();
            }
            void insert(const string& s){
                Node* curr = root;
                for(const char c: s){
                    if(!curr->children.count(c)){
                        Node* n = new Node(c);
                        curr->children[c] = n;
                    }
                    curr = curr->children[c];
                }
            }
            bool contain(const string& s){
                Node* curr = root;
                for(const char c: s){
                    if(!curr->children.count(c)){
                        return false;
                    }
                    curr = curr->children[c];
                }
                return true;
            }
    };
    int minimumLengthEncoding(vector<string>& words) {
        auto cmp = [](const string& a, const string& b){return a.length() > b.length();};
        sort(words.begin(), words.end(), cmp);
        Rev_Trie rev_trie;
        int ans = 0;
        for(const string& word: words){
            string rev_word = word;
            reverse(rev_word.begin(), rev_word.end());
            if(!rev_trie.contain(rev_word)){
                ans += word.size() + 1;
                rev_trie.insert(rev_word);
            }
        }
        return ans;
    }
};
// @lc code=end

