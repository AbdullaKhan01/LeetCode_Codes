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
    ListNode* reverseLL(ListNode* &head){
        if(head == NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* chotaHead = reverseLL(head->next);
        head -> next -> next = head;
        head -> next = NULL;

        return chotaHead;
    }
    ListNode* mid(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast -> next->next;
            slow=slow->next;
        }
        return slow;
    }
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        ListNode* temp2 = mid(head);
        temp2=reverseLL(temp2);
        int maxi = INT_MIN;
        while(temp!=NULL && temp2!=NULL){
            maxi = max(maxi,temp->val+temp2->val);
            temp = temp->next;
            temp2= temp2->next;
        }
        return maxi;
    }
};
