/*
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.        

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M))

Constraints:
1 <= N, M <= 5000
*/

1.


class Solution
{
    public:
       Node* reverseList(Node* head) {
        Node* prev=NULL;
        Node* curr=head;
        Node* n;
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
    
    
    public:
       Node*  sum(struct Node* first, struct Node* second){
             Node *rheadfirst = reverseList(first);
             Node * rheadsecond = reverseList(second);
             Node *l1=new Node(0);
             Node *l2=l1;
             
             int carry=0;
             while(rheadfirst and rheadsecond){
                 int num = rheadfirst->data + rheadsecond->data+carry;
                 Node *digit = new Node(num%10);
                 carry=num/10;
                 l1->next=digit;
                 rheadfirst=rheadfirst->next;
                 rheadsecond=rheadsecond->next;
                 l1=l1->next;
                 
                 
             }
             
             while(rheadfirst){
                int num = rheadfirst->data +carry;
                 Node *digit = new Node(num%10);
                 carry=num/10;
                 l1->next=digit;
                 rheadfirst=rheadfirst->next;
                
                 l1=l1->next;
                 
             }
            
            
             while(rheadsecond){
                 int num =rheadsecond->data+carry;
                 Node *digit = new Node(num%10);
                 carry=num/10;
                 l1->next=digit;
                
                 rheadsecond=rheadsecond->next;
                 l1=l1->next;
            
             }
             if(carry==1){                                   
                 Node* digit = new Node(carry);
                 l1->next=digit;
        }
             return l2->next;
       }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
             Node *temp=sum(first, second);
             return  reverseList(temp);
    }
};



