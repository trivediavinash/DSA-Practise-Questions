/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

*/
1.Using STACK or VECTOR o(n) o(n)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int>s;
       ListNode* p=head;
        while(p!=NULL ){
            s.push(p->val);
            p=p->next;
        }
         p=head;
        while(!s.empty()){
            
            if(p->val!=s.top()){
                return false;
               
            }
            p=p->next;
            s.pop();
          
        }
        return true;
    }
};

2. 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int>v;
     //  bool ans =true;
        ListNode* p=head;
        while(p!=NULL ){
            v.push_back(p->val);
            p=p->next;
        }
        
        p=head;
        int n=v.size();
       for(int i=0;i<v.size()/2;i++)
       {
            if(v[i]!=v[n-i-1]) {
       
            return false; 
           }
       
       
         
        
    }
    return true;

3. O(N/2) For finding Middle elemnt + O(N) for comparing left and right elemnts

O(N)  O(N)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *prev= NULL, *slow=head, *fast=head, *temp;
        while(fast && fast->next){   //here fast->next for even length 1 2 2 1 
            fast=fast->next->next;
            temp=slow->next;  
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        if(fast) slow=slow->next; //slow pointer will always be at the middle elemnt .  it is for odd lenght of linklist
        while(slow){
            if(prev->val!=slow->val) return false ;
            prev=prev->next;
            slow=slow->next;
        }
        return true;
    }
};

