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

ListNode* reverse(ListNode* head, int times) {
    ListNode* curr = head;
    ListNode* prev = NULL;

    while (times-- && curr != NULL) {
        ListNode* nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }

    return prev;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == NULL || k == 1) {
            return head;
        }

        ListNode* left = head;
        ListNode* res = NULL;
        ListNode* prevleft = NULL;

        while (left != NULL) {

            // Check if there are at least k nodes
            ListNode* temp = left;

            for (int i = 0; i < k; i++) {
                if (temp == NULL) {
                    if (prevleft) {
                        prevleft->next = left;
                    }
                    return res;
                }

                temp = temp->next;
            }

            // Store the next group's starting node
            ListNode* nextleft = temp;

            // Reverse current k nodes
            ListNode* right = reverse(left, k);

            // Store the tail of the reversed group
            ListNode* tail = left;

            // First reversed group becomes the result head
            if (res == NULL) {
                res = right;
            }

            // Connect previous group to current group
            if (prevleft) {
                prevleft->next = right;
            }

            // Connect current group to next group
            tail->next = nextleft;

            // Move to next group
            prevleft = tail;
            left = nextleft;
        }

        return res;
    }
};