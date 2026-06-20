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
    void reorderList(ListNode* head) {
        ListNode *slow = head ;
        ListNode *fast = head ;

        while (fast != NULL && fast->next != NULL){
            slow = slow -> next ;
            fast = fast -> next -> next ;
        }

        ListNode *second = slow->next ;
        slow -> next = nullptr ;  // ending the connection of node 3 and now node 3 points to NULL 
        ListNode *prev = nullptr ;
        ListNode *curr = second ;
        

        while (curr != nullptr){
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr ;
            curr = nextTemp;
        }

        ListNode *p1 = head;
        ListNode *p2 = prev;

        while (p2 != nullptr){
            ListNode *p1Next = p1->next;
            ListNode *p2Next = p2->next;

            p1 -> next = p2;

            if(p1Next != nullptr){
                p2 -> next = p1Next;
            }

            p1 = p1Next;
            p2 = p2Next;
        }   
    }
};