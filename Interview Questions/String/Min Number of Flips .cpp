/*
Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.

Example 1:

Input:
S = "001"
Output: 1
Explanation: We can flip the 0th bit to 1
to have "101".
â€‹Example 2:

Input: 
S = "0001010111"
Output: 2
Explanation: We can flip the 1st and 8th bit
to have "0101010101".

Your Task:
You don't need to read input or print anything. Your task is to complete the function minFlips() which takes the string S as input and returns the minimum number of flips required.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).


Constraints:
1<=|S|<=105
*/

1. O(N) O(1)

//Only 2 possibilities are there. First to have a sequence "010101..." and second to have a sequence "1010101...".

//Calculate the flips required to convert the string into both and return the minimum
int minFlips(string S) {

  int n = S.length();

  if (n == 1) return 0;
  int even0 = 0, odd1 = 0, even1 = 0, odd0 = 0;
  for (int i = 0; i < n; i++) {
    //for 0101010 pattern

    if (i % 2 == 0 && S[i] == '1') even0++; //counting number of position  where 0 shoul be at even postion but 1 is there so we can flip it
    if (i % 2 == 1 && S[i] == '0') odd1++; //counting number of position  where 1 shoul be at odd postion but 0 is there so we can flip it
    // for 10101010 pattern

    if (i % 2 == 0 && S[i] == '0') even1++; // counting number of position  where 1 shoul be at even postion but 0 is there so we can flip it
    if (i % 2 == 1 && S[i] == '1') odd0++; /// counting number of position  where 0 should be at odd postion but 1 is there so we can flip it
  }
  return min((even0 + odd1), (even1 + odd0++)); //returning minimum of two 
}


