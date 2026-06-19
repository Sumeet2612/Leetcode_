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
    bool isPalindrome(ListNode* head) {
        
        if (!head || !head->next) return true;

        // Phase 1: find start of second half
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalfStart = (fast) ? slow->next : slow;

        ListNode *prev = nullptr, *curr = secondHalfStart;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode *first = head, *second = prev;
        bool isPalin = true;
        while (second) {
            if (first->val != second->val) {
                isPalin = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        return isPalin;
    }
};