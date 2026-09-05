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

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right) {
            return head;
        }

        ListNode* t = head;
        ListNode* before = NULL;
        int pos = 1;

        // Move t to the node at position 'left'
        while (pos < left) {
            before = t;
            t = t->next;
            pos++;
        }

        // Reverse the nodes from left to right
        ListNode* curr = t;
        ListNode* prev = NULL;

        int times = right - left + 1;

        while (times--) {
            ListNode* nex = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nex;
        }

        t->next = curr;

        if (before != NULL) {
            before->next = prev;
            return head;
        }

        return prev;
    }
};