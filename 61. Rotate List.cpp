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
    int lengthOfList(ListNode* head){
        int count = 0;
        while(head!=NULL){
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL)
            return head;
        int size = lengthOfList(head);
        int rot = k%size;
        if(rot==0)
            return head;
        ListNode* temp = head;
        ListNode* ans;
        int l = size - rot - 1;
        int m = size - rot;
        int count = 1;
        while(l--)
            temp = temp -> next;
        ListNode* NewHead = temp->next;
        ListNode* temp2=NewHead;
        temp -> next = NULL;
        while(temp2!=NULL && temp2->next!=NULL)
            temp2=temp2->next;
        temp2->next = head;
        return NewHead;
        // while(temp->next != NULL){
        //     if(count == m){
        //         ans = temp->next;
        //         temp -> next = NULL;
        //         temp = ans;
        //         }
        //     else
        //         temp = temp->next;
        //     count++;
        // }
        // temp->next = head;
        // return ans;
    }
};
