/*
Give a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

 

Example 1:

Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:

Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.
*/

1. O(N), O(n);
class Solution {
  public:
    int countBinarySubstrings(string s) {
      vector < int > groups;
      int n = s.length();
      int count = 1;
      //making groups of conscutive ones or zeroes and storing them into vector and thrn taking minimum of consecutive two groups .
      // for eg 00110011,  groups = 2, 2, 2, 2 take minimum of consecutive these all groups 2+@+2 = 6
      // 0011 = we can make min(2,2) we can make two substring only
      // 1100 = we canmake min(2,2) again two sunstrings are posssible       
      for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) count++;
        else {
          groups.push_back(count);
          count = 1;
        }
      }
      groups.push_back(count); //for last count of zeroes or ones
      int ans = 0;
      for (int i = 1; i < groups.size(); i++) {
        ans += min(groups[i - 1], groups[i]);
      }
      return ans;
    }
};

2. O(N) O(1)

class Solution {
  public:
    int countBinarySubstrings(string s) {
      vector < int > groups;
      int n = s.length();
      int count = 1;
      //making groups of conscutive ones or zeroes and storing them into vector and thrn taking minimum of consecutive two groups .
      // for eg 00110011,  groups = 2, 2, 2, 2 take minimum of consecutive these all groups 2+@+2 = 6
      // 0011 = we can make min(2,2) we can make two substring only
      // 1100 = we canmake min(2,2) again two sunstrings are posssible 
      int ans = 0, prev = 0;
      for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) count++;
        else {
          ans += min(prev, count);
          prev = count;
          count = 1;
        }
      }
      //min(prev, count) coz we want to add last consecutive group also   // required to include count from last two groups of consecutive characters.
      return ans + min(prev, count);
    }
};

/*
1. 0011
In this string, consecutive count of binary characters are [2, 2]. We can form a total of 2 substrings.

2. 00011
In this string, consecutive count of binary characters are [3, 2]. Still, we can only form 2 substrings.

3. 000111
Here, consecutive count of binary characters are as - [3,3]. Now, we can form 3 substrings.

4. 00011100
Consecutive count of binary characters are - [3,3,2]. We can form 3 substrings with the first 2 groups of zeros and ones. 
Then we can form 2 substrings with the latter 2 groups. So, a total of 5 substrings.

5. 00011100111
*/
