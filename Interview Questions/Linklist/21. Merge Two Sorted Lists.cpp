/*
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

 

Example 1:


Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]
*/

1. Recursive 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3;
        if(l1==NULL){
        return l2;
       }
       if(l2==NULL){
        return l1;
        }
        if(l1->val<=l2->val){
            l3=l1;
            l3->next=mergeTwoLists(l1->next,  l2);
                
            }
        else {
            l3=l2;
            l3->next=mergeTwoLists(l1,l2->next);
        }
        return l3;
    }
};

2.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode*l3= new ListNode(0);
         ListNode*l4=l3;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
         while(l1 and l2){
             if(l1->val<l2->val){
                 l3= new ListNode(l1->val);
                 l3=l3->next;
                 l1=l1->next;
             }
                 
              else{
                  l3= new ListNode(l2->val);
                   l3=l3->next;
                   l2=l2->next;
              }
             if(l)
                 l3=l3->next;
                 
           
         }
        while(l1){
                 l3= new ListNode(l1->val);
                  l3=l3->next;
                 l1=l1->next;
        }
        while(l2){
             l3->next= new ListNode(l2->val);
             l3=l3->next;
             l2=l2->next;
        }
        return l4->next;
    }
};

2.



class Solution {
  public:
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
      ListNode * l3 = new ListNode(0);
      ListNode * l4 = l3;
      if (l1 == NULL) return l2;
      if (l2 == NULL) return l1;

      while (l1 and l2) {
        if (l1 -> val < l2 -> val) {
          l3 -> next = new ListNode(l1 -> val);

          l1 = l1 -> next;

        } else {
          l3 -> next = new ListNode(l2 -> val);

          l2 = l2 -> next;
        }
        l3 = l3 -> next;

      }
      /*   while(l1){
                  l3->next= new ListNode(l1->val);
                   l3=l3->next;
                  l1=l1->next;
         }
         while(l2){
              l3->next= new ListNode(l2->val);
              l3=l3->next;
              l2=l2->next;
         }   */
      //Alternatively 
      if (l1 == NULL) l3 -> next = l2; //if one of list is exhausted then just shift pointer of newly formed list to another list as elements in second list are alredy sorted;
      if (l2 == NULL) l3 -> next = l1;
      return l4 -> next;
    }
};
