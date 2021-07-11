/*
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 101000

Company Tags
 Amazon*/

1. o(N) O(1);

class Solution
{ 
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
    Node* addOne(Node *head) 
    {
        Node *rhead = reverseList(head);
        Node *curr = rhead,*prev = rhead;
        int carry = 0;
        int sum = rhead->data +carry+1;
        curr->data =sum%10 ;
        carry = sum/10;
        curr = curr->next;
        while(curr){
                 int sum = curr->data +carry;
                 curr->data = sum%10;
                 carry=sum/10;
                 prev=curr;
                 curr=curr->next;
                
                
        }
        if(carry==1){                                   
                 
                 prev->next =new Node(carry);
        }
        return reverseList(rhead);
    }
};

