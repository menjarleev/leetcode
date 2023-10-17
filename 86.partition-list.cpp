/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */
#include "lc.hpp"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *next = nullptr;
        ListNode *before = new ListNode();
        ListNode *after = new ListNode();
        ListNode *curr_before = before;
        ListNode *curr_after = after;
        while (head)
        {
            next = head->next;
            if (head->val < x)
            {
                curr_before->next = head;
                curr_before = head;
            }
            else
            {
                curr_after->next = head;
                curr_after = head;
            }
            curr = next;
        }
        curr_after->next = nullptr;
        curr_before->next = after->next;
        return before->next;
    }
};
// @lc code=end
