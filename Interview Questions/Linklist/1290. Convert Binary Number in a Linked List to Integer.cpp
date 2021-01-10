/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

 

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
Example 3:

Input: head = [1]
Output: 1
Example 4:

Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880
Example 5:

Input: head = [0,0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
*/

1.Method 1 conventional formula for converting binary to decimal   

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *temp =head;
        int len=0;
        while(head->next!=NULL){
        len++;
       head=head->next;
   }
      
   int res =0;
   
   
      while(temp!=NULL){
         // if(temp->val==1)
          res+=temp->val*pow(2,len);
          len--;
          temp=temp->next;
      
       }
         return res;
    }
};





2. Using Vector  extra space will be used

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *temp =head;
        vector <int> v;
        while(head->next!=NULL){
          v.push_back(head->val);
          head=head->next;
      }
      
   int res =0;
   int len =v.size();
      while(temp!=NULL){
         // if(temp->val==1)
          res+=temp->val*pow(2,len);
          len--;
          temp=temp->next;
      
       }
         return res;
    }
};

3.Most Optimized

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *temp =head;
        
        int res =head->val;  ///Initialise the value res of forst node a and then do operarion from data of next node.
        while(head->next!=NULL){
          res=res*2+head->next->val;
          head=head->next;
      }
      
   
         return res;
    }
};
