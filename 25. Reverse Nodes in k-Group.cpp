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
    ListNode* reverse(ListNode* head,ListNode* end){
        if(head==end || head-> next == end)
            return head;
        ListNode* chotaHead = reverse(head->next,end);
        head -> next -> next = head;
        head -> next = NULL;
        return chotaHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k==1)
            return head;
        ListNode * dummy = new ListNode(0);
        ListNode* tail= dummy;
        ListNode* temp2=head;
        while(temp2!= NULL ){
            ListNode* start = temp2;
            int count = 0;
            int n=k;
            while(n-- && temp2!=NULL){
                count++;
                temp2= temp2->next;
            }
            ListNode* end = temp2;
            
            if(count<k){
                tail -> next= start;
            }
            else tail -> next = reverse(start,end);
            tail = start;
        }
        return dummy->next;
    }
};
