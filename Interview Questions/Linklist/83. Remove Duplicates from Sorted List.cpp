/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/

1.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return 0;
        
        
        ListNode* curr=head;
        while(curr!=NULL && curr->next!=NULL){
               if(curr->next->val==curr->val){
                    ListNode *temp=curr->next;
                    curr->next=curr->next->next;
                    delete temp;  //We must delete curr pointer which was pointing to duplicate node to avoid memory leak as there is no garbage collection in cpp
               }
                
         else{
             curr=curr->next;   
          }
           
        }
        return head;

    }
};

2.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return 0;
        ListNode* prev =head;
        
        ListNode* curr=head->next;
        while(curr!=NULL ){
               if(curr->val==prev->val){
                   ListNode*temp=prev->next;
                   prev->next= curr->next;
                   
                   curr=curr->next;
                   delete temp;           //We also need to update the curr like 1 1 1 2 2 
               }
                
               else{
                   prev=curr;
                   curr=curr->next;
               }
        }
        return head;

    }
};
