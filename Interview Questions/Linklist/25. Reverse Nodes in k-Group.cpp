/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Follow up:

Could you solve the problem in O(1) extra memory space?
You may not alter the values in the list's nodes, only nodes itself may be changed.
 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
Example 4:

Input: head = [1], k = 1
Output: [1]
 

Constraints:

The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz

*/

1. O(n/k)*k =O(n) O(1)


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or k==1) return head;
         ListNode* dummy= new ListNode(0);
         dummy->next = head;
         ListNode *prev = dummy, *nex=dummy, *curr=dummy;
         int count=0;
         while(curr->next!=NULL){
             curr=curr->next;
             count++;
         }
        
        int total_group=count/k;
        
        while(total_group>0){
            curr=prev->next;
            nex=curr->next;
            int i=0;
            while(i<k-1){
                curr->next=nex->next;
                nex->next=prev->next; // To keep track of prev node 
                prev->next=nex;
                nex=curr->next;
                i++;
            }
            count-=k;
            prev=curr;
            
            total_group-=1;
        }
        
         return dummy->next;
    }
};

2. Recursive solution 
/* 1 2 3 4 5 6 7 8 k=3
   on first call prev =3 and head =1
   on second call prev =6 and head= 4
   on third call head will returned of sub-linklist  7 8
  */

class Solution {
public:
    
    int len(ListNode* node){
        int lenght =0;
        while(node){
            lenght++;
            node=node->next;
        }
        return lenght;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or  k==1 ) return head;
        if(len(head)<k) return head;
        ListNode *curr=head, *prev=NULL;
        for(int i=0;i<k;i++){
           ListNode *n= curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        head->next= reverseKGroup(curr, k);  //Connecting head of each linklist of group k to every other  linklist   
        return prev;  
    }
};
