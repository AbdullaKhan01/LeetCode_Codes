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
struct node_cmp
{
   bool operator()(ListNode* a,ListNode* b ) 
   {
    return a->val > b->val;
   }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,node_cmp> minHeap;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
            minHeap.push(lists[i]);
        }
        while(minHeap.size()>0){
            ListNode* top = minHeap.top();
            minHeap.pop();
            if(top->next !=NULL){
                minHeap.push(top->next);
            }
            if(head == NULL){
                //if inserting at the first node
                head = top;
                tail = top;
            }
            else{//insert at tail
                tail -> next = top;
                tail = top;
            }
        }
        return head;
    }
};
