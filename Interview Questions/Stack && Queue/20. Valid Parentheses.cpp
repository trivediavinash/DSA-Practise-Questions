/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
*/

1. O(N) O(N)

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
         st.push(s[0]);
        for(int i=1;i<s.size();i++){
           
                
            if(st.empty()) st.push(s[i]);
            
            else if(st.top()=='{' && s[i]=='}' or st.top()=='[' && s[i]==']' or st.top()=='(' && s[i]==')'){
               
                st.pop();
               
            }
            
             else{
                 st.push(s[i]);
              
                
             }  
                
          
           
              
           
        }
        if(st.size()>0) return false;
        else return true;
    }
};
