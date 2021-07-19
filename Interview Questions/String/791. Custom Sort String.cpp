/*
order and str are strings composed of lowercase letters. In order, no letter occurs more than once.

order was sorted in some custom order previously. We want to permute the characters of str so that they match the order that order was sorted. More specifically, if x occurs before y in order, then x should occur before y in the returned string.

Return any permutation of str (as a string) that satisfies this property.

Example:
Input: 
order = "cba"
str = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
 

Note:

order has length at most 26, and no character is repeated in order.
str has length at most 200.
order and str consist of lowercase letters only.
*/

1. O(n^2) O(N)

class Solution {
  public:
    string customSortString(string order, string str) {

      unordered_map < char, int > ordermap;
      string ans = "";
      string temp = "";

      for (auto i = 0; i < order.length(); i++) { // O(n)
        ordermap[order[i]]++;
      }

      // checking the cont of charcter in order  and appending it to another string 
      for (auto i: order) { // O(n^2) 
        int x = count(str.begin(), str.end(), i);
        for (int j = 0; j < x; j++) {
          ans.push_back(i);
        }

      }
      //charcter which were not present in order but present in str are appended to another string 
      for (auto i: str) { //    O(n)
        if (ordermap.find(i) == ordermap.end()) temp.push_back(i);
      }

      return ans + temp;
    }
};

2 O(n) O(1)

class Solution {
  public:
    string customSortString(string order, string str) {
      unordered_map < char, int > mp;
      string s = "";
      for (auto ch: str) {
        mp[ch]++;
      }
      //checking if ch is in order if it is in order then append till its frequecny exhaust .
      for (auto ch: order) {
        if (mp.find(ch) != mp.end()) {
          auto it = mp.find(ch);
          while (it -> second > 0) {
            s += it -> first;
            it -> second -= 1;
          }
          mp.erase(it); //erase those chacteros which are founded
        }
      }

      //appending those elements which are not present in the order but present in string 
      for (auto it: mp) {
        while (it.second > 0) {
          s += it.first;
          it.second--;
        }
      }
      return s;

    }
};
