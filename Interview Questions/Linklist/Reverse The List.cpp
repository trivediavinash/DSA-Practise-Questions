/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

1. Iterative sol

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* n;
        if(head==NULL){
            return head;
        }
        while(curr!=NULL){ 
            n=curr->next;       //to store pointer which is pointing to next node
            curr->next=prev;    //pointing curr node to previos
            prev=curr;         // making previous to current node
            curr=n;            //pointing current node to nect node
           head=prev;          //updating head as prev node
            
            
        }
        return head;
    }
};

2. Recursive Sol

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;  //for base case when only one empty node [].
        if( head->next==NULL){
            return head;
        }
        ListNode* shead=  reverseList(head->next);
        ListNode*temp=head->next; //Aternatively withou using temp node 
        temp->next=head;     //head -> next -> next = head;
                             //head -> next = NULL;
        head->next=NULL;
       
        return shead;
    }
    
};