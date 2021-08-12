/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

1.1//sorting then checking the anargams O(nlogn + mlogm + O(n))   O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        int i = 0 , j = 0 ;
        while(i < s.length() && j < t.length()){
            if(s[i]!=t[j]) return false;
            i++;
            j++;
        } 
        return true;
    }
};
1.2
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t ;
    }
};

2 . O(n) O(26)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false; //if two strings are of diffrent length then they will never be anargams
        
        unordered_map <char, int > um;
        for(int i = 0 ; i< t.length(); i++){
            um[t[i]]++;
        }
         for(int i = 0 ; i< s.length(); i++){   //checking charcters of another string and subtracting the freq of same character in the hashmap.
             if(um.count(s[i])) um[s[i]]--;
         }
      
        for(auto it = um.begin(); it != um.end(); it++){   //checking hashmap for freqncies
            if(it->second>0) return false;
        }
        return true;
    }
};

2.1

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map <char, int > um;
        for(int i = 0 ; i< t.length(); i++){
            um[t[i]]++;   //pusing in hashmap and subtracting from it at the same time also  freq of character from another string .
            um[s[i]]--;
        }
         
      
        for(auto it = um.begin(); it != um.end(); it++){
            if(it->second) return false;
        }
        return true;
    }
};


3.

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;  //it is increasing the counter at specific loaction in counts where should the current character will lie in abcdefghijklmn order .  lik a will lie at 0 position and b will be at 1 likewise
            counts[t[i] - 'a']--;  //and it will decrease the counter at specififc location .
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;   //if counter is grater than 0 .
        return true;
    }
};
