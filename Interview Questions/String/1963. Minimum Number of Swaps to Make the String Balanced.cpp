/*
You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.

 

Example 1:

Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
Example 2:

Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
Example 3:

Input: s = "[]"
Output: 0
Explanation: The string is already balanced.
 

Constraints:

n == s.length
2 <= n <= 106
n is even.
s[i] is either '[' or ']'.
The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.
*/

1. O(N) O(1)
//Logic - we need to check just unbalanced brackets , we are counting just unbalanced brackets 

class Solution {
  public:
    int minSwaps(string s) {
      int stack_size = 0, unbalanced_count = 0;
      for (int i = 0; i < s.length(); i++) {

        if (s[i] == '[') stack_size++;
        else if (stack_size == 0) unbalanced_count++;
        else if (s[i] == ']') stack_size--;

      }
      /*if mismatches is even --> return mismatches / 2
else return (mismatches + 1) / 2
        */
      /*let say you got 6 pairs then you will have to swap 3 times but what about 5 pairs first two swaps will align 4 pairs, but you will need one more swap to align the 5th one .
       */
      return (unbalanced_count + 1) / 2;
    }
};

2. O(N) O(N)

class Solution {
  public:
    int minSwaps(string s) {
      stack < char > st;
      int unbalanced_count = 0;
      for (int i = 0; i < s.length(); i++) {

        if (s[i] == '[') st.push(s[i]);
        else if (st.size() == 0) unbalanced_count++;
        else if (s[i] == ']') st.pop();

      }
      /*if mismatches is even --> return mismatches / 2
else return (mismatches + 1) / 2
        */
      /*let say you got 6 pairs then you will have to swap 3 times but what about 5 pairs first two swaps will align 4 pairs, but you will need one more swap to align the 5th one .
       */
      return (unbalanced_count + 1) / 2;
    }
};

3. two pointer approach

