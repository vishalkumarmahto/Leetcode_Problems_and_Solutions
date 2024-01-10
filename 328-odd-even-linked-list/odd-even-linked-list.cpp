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
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head;

    //Creating odd and even pointer
    ListNode* slow=head;
    ListNode* fast=head->next;

    //storing start pointer of even
    ListNode* ans=fast;

    //traversing and changing node pointers
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        ListNode* aftereven=fast->next->next;
        slow->next=fast->next;
        slow=fast->next;
        slow->next=NULL;
        fast->next=aftereven;
        fast=aftereven;
    }
    //only for odd number condion 
    if(fast->next!=NULL){
    slow->next=fast->next;
    slow=slow->next;
    slow->next=NULL;
    fast->next=NULL;
    }
    //Connecting odd even list
    slow->next=ans;
    return head;
           }
};