/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


It is guaranteed that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

 

Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
Example 2:


Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
Example 3:


Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
 

Constraints:

The number of nodes of listA is in the m.
The number of nodes of listB is in the n.
1 <= m, n <= 3 * 104
1 <= Node.val <= 105
1 <= skipA <= m
1 <= skipB <= n
intersectVal is 0 if listA and listB do not intersect.
intersectVal == listA[skipA + 1] == listB[skipB + 1] if listA and listB intersect.
 

Follow up: Could you write a solution that runs in O(n) time and use only O(1) memory?

*/

1. T.c = O(N) S.c.= O(1)


/* Approach  1. find length of both lists
             2. advance pointer to heads according to length of both the lists whichever is small or large and keep both pointers at the same distance from head pf both list
             3. compare if pointers pointing to same node
*/ 
class Solution {
public:
    //Lenght of listA
    int  lenghtA(ListNode *tempa){
     int la=1;
     while(tempa){
         tempa=tempa->next;
         la++;
     }
     
        return la ;
    }
    //lenght of listB
    int  lenghtB(ListNode *tempb){
       int lb=1;
       while(tempb){
          tempb=tempb->next;
          lb++;
     } 
        return lb;
    } 
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * tempa=headA;
        ListNode * tempb=headB;
        int la=lenghtA(tempa);
        int lb=lenghtB(tempb);
       
        int diff1 = abs(la-lb);
        //comparing lenght of both the lists
        if(lb>la){
           while(diff1){
           //ListNode *tempb=headB;
           tempb=tempb->next;
            diff1--;
           }
        
          }
       else {
           while(diff1){
             //ListNode *tempa=headA;
             tempa=tempa->next;
             diff1--;
        } 
    }
        //checking if pointers pointing to same node if not return NULL;
        while(tempa and tempb ){
            if(tempa==tempb){
                return tempa;
            }
            else {
                tempa=tempa->next;
                tempb=tempb->next;
            }
        }
        return NULL;
    }
};

2.

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        
         if (p1 == NULL || p2 == NULL) return NULL;

         while ( p1 != p2) {    
           p1 = p1->next;
           p2 = p2->next;

        
            // Any time they collide or reach end together without colliding 
            // then return any one of the pointers.
        
           if (p1 == p2) return p1;   

          
            // If one of them reaches the end earlier then reuse it 
            // by moving it to the beginning of other list.
            // Once both of them go through reassigning, 
            // they will be equidistant from the collision point.
        
          if (p1 == NULL) p1 = headB;
          if (p2 == NULL) p2 = headA;
        }
        
       return p1;
    }
