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

    ListNode* swapPairs(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* left = head;
        ListNode* right;
        ListNode* res = NULL;
        ListNode* prevleft = NULL;

        int size = 2;

        while (left != NULL) {

            right = left;

            if (right->next == NULL) {
                if (prevleft) {
                    prevleft->next = left;
                }
                break;
            }

            ListNode* nextleft = left->next->next;

            right = reverse(left, size);

            if (res == NULL) {
                res = right;
            }

            if (prevleft) {
                prevleft->next = right;
            }

            prevleft = right->next;
            left = nextleft;
        }

        return res;
    }
};