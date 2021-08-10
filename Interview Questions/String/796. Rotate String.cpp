/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.
*/

1. O(n^2) O(N+M)

//we are concanating the string a and then searching ourgola string in concanated string

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        s+=s;   
        //npos It actually means until the end of the string.As a return value, it is usually used to indicate no matches.
        if(s.find(goal)!=string::npos) 
            return true;
        return false;
    }
};
