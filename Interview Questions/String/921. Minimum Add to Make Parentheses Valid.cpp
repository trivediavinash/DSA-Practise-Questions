/*
A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

 

Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3
Example 3:

Input: s = "()"
Output: 0
Example 4:

Input: s = "()))(("
Output: 4
 

Constraints:

1 <= s.length <= 1000
s[i] is either '(' or ')'.
*/

1. O(N) O(N) 

//Logic we are just concernig with brackets which are balanced and counting them and finally we will subtract the balanced brackets from total beackets to find unbalanced brackets.
class Solution {
  public:
    int minAddToMakeValid(string s) {
      stack < char > st;
      int ans = 0;

      int n = s.length();
      for (int i = 0; i < n; i++) {
        if (s[i] == '(') st.push(s[i]); //pusing the open paranthesis

        else if (s[i] == ')' && !st.empty()) { //checking for closing paranthesis if it is and stack is not empty  then only we will pop the opening paranthesis from the stack and count the increase of balanced paranthesis
          st.pop();

          ans = ans + 2; //increase of balanced paranthesis

        }
      }
      // unbalanced brackets = total brackts - unbalanced brackets
      return n - ans; //returning the unbalanced brackets 

    }
};

2. O(N) O(1)

class Solution {
  public:
    int minAddToMakeValid(string s) {
      int left = 0, right = 0;

      int n = s.length();
      for (int i = 0; i < n; i++) {
        //we are increasing the right variable because if current char is '(' opening paranthesis then we will need ')' in future .
        if (s[i] == '(') right++;
        // if it is alreday closing paranthesis and right has some value alredy then we will decrement it as we are trying to cancel out the balanced paranthesis . 
        else if (s[i] == ')' && right != 0) {
          right--;

        } else if (s[i] == ')' && right == 0) left++; //if we encounter closing paranthesis and righ==0  it means we have already canceled out the balanced paranthesis and we will increment left pointer to balance the current closing paranthesis .
      }

      return left + right;
    }
};
