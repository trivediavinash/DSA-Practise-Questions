/*
Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105

*/
1. Top Down 
/*Complexity Analysis

Time Complexity: O(nlogn), where n is the number of nodes in linked list. The algorithm can be split into 2 phases, Split and Merge.
Let's assume that n is power of 2. For n = 16



Split

The recursion tree expands in form of a complete binary tree, splitting the list into two halves recursively. The number of levels in a complete binary tree is given by log base 2 n


Merge

At each level, we merge n nodes which takes
Space Complexity: log n . Since the problem is recursive, we need additional space to store the recursive call stack. The maximum depth of the recursion tree is logn
*/

1. Top down 

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        
        
            ListNode*slow=head;
            ListNode* fast= head;
            while(fast->next!=NULL and fast->next->next!=NULL ){   //if no of nodes are even fast will be null if odd fast->next will be null.
            
               slow=slow->next;
               fast=fast->next->next;
               }
              // Breaking the list into two parts.
              fast=slow->next;
              slow->next=NULL;
              
              
        
      
        ListNode* left=sortList(head);
        ListNode* right=sortList(fast);
        
        return  mergelists(left, right);
        
    }
        
        ListNode* mergelists(ListNode* list1, ListNode* list2){
            ListNode *ans=new ListNode(0);
            ListNode *list3=ans;
            while(list1 && list2){
                if(list1->val>list2->val){
                    list3->next=list2;
                    list2=list2->next;
                }
                else {
                    list3->next=list1;
                    list1=list1->next;
               }
              list3=list3->next;
            }
                
            if(list1) list3->next=list1;
            else list3->next= list2;
                
              
                
       
            return ans->next; 
        }
        
};

1.1

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        
        ListNode* mid=middleNode(head);
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);
       return  mergelists(left, right);
        
    }
        
        ListNode* mergelists(ListNode* list1, ListNode* list2){
            ListNode *ans=new ListNode(0);
            ListNode *list3=ans;
            while(list1 && list2){
                if(list1->val>list2->val){
                    list3->next=list2;
                    list2=list2->next;
                }
                else {
                    list3->next=list1;
                    list1=list1->next;
               }
              list3=list3->next;
            }
                
            if(list1) list3->next=list1;
            else list3->next= list2;
                
              
                
       
            return ans->next; 
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ListNode* middleNode(ListNode* head) {
            ListNode*slow=head;
            ListNode* fast= head->next;
            while(fast!=NULL and fast->next!=NULL ){   //if no of nodes are even fast will be null if odd fast->next will be null.
            
               slow=slow->next;
               fast=fast->next->next;
               }
              // Breaking the list into two parts.
              fast=slow->next;
              slow->next=NULL;
              
              return fast;
    }
    
};
