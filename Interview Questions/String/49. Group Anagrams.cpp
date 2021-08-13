/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.
*/

1.// Use the sorted string as the key and all anagram strings as the value.

mlogm (sorting each string) * O(n) (no of strings in vector) + O(n) (for traversing the map) 
s.c. = O(m*N);  

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map < string, vector<string>> um;
        
        int n = strs.size();
        for(int i = 0 ;i < n ; i++){
            string t = strs[i] ; 
            sort(t.begin(), t.end());
            um[t].push_back(strs[i]); //making key as sorted string ...and grouping all anargams as value 
        }
        vector<vector<string >> ans; 
        for(auto it = um.begin(); it != um.end(); it++){
            ans.push_back(it->second);   //here it->second is a vector which will contain all anargams
        }
        return ans;
        
    }
};

2. o(m) or o(26) (sorting each string) * O(n) (no of strings in vector) + O(n) (for traversing the map) 
s.c. = O(26*N); 


//doubt in bucket sorting custom funtion 
class Solution {
  public:
    vector < vector < string >> groupAnagrams(vector < string > & strs) {
      unordered_map < string, vector < string >> um;

      int n = strs.size();
      for (int i = 0; i < n; i++) {

        um[sortLowercase(strs[i])].push_back(strs[i]); //making key as sorted string ...and grouping all anargams as value 
      }
      vector < vector < string >> ans;
      for (auto it = um.begin(); it != um.end(); it++) {
        ans.push_back(it -> second); //here it->second is a vector which will contain all anargams
      }
      return ans;

    }
  //bucket sorting  
  private:
    string sortLowercase(string s) {
      int charExist[26] = {
        0
      };
      for (int i = 0; i < s.size(); i++) {
        charExist[s[i] - 'a']++; //storing freq of each character
      }
      string res;
      int j = 0;
      while (j < 26) {
        if (charExist[j] == 0) { //if freq is zero in array table it means particular character wass not present in original string  
          j++; // so we have increased the pointer 
        } else {
          res.push_back(j + 'a'); //
          charExist[j]--;
        }
      }
      return res;
    }
};
