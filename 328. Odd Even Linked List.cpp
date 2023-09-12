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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* chotaHead = head;
        ListNode* secondHead = head->next;
        ListNode* temp = secondHead;
        // ListNode* mid = m(head);
        while(chotaHead != NULL && secondHead !=NULL){
            if(chotaHead -> next !=NULL){
            chotaHead -> next = chotaHead->next->next;
            if(chotaHead->next != NULL)
                chotaHead = chotaHead->next;
            else break;
            }

            if(secondHead->next !=NULL){
                secondHead->next = secondHead->next->next;
                secondHead = secondHead->next;
            }
        }
        chotaHead -> next = temp;
        return head;
        
    }
};
