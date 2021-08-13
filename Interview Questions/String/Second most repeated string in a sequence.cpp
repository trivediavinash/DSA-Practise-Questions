/*
Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Example 1:

Input:
N = 6
arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
Output: bbb
Explanation: "bbb" is the second most 
occurring string with frequency 2.

â€‹Example 2:

Input: 
N = 6
arr[] = {geek, for, geek, for, geek, aaa}
Output: for
Explanation: "for" is the second most
occurring string with frequency 2.

Your Task:
You don't need to read input or print anything. Your task is to complete the function secFrequent() which takes the string array arr[] and its size N as inputs and returns the second most frequent string in the array.


Expected Time Complexity: O(N*max(|Si|).
Expected Auxiliary Space: O(N*max(|Si|).


Constraints:
1<=N<=103

 

Company Tags
 Amazon Goldman Sachs
*/
//Expected Time Complexity: O(N*max(|Si|).
//Expected Auxiliary Space: O(N*max(|Si|).
1. O(N)* lenght of individaul string O(m)    O() 

//Store the frequency of all the strings in a hash map. Check the second highest of all the freuqencies. Then, traverse the hash map and find the string with that frequency
class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
       string ans ;
       unordered_map<string, int>um;
       for(int i = 0 ; i<n ; i++){
           um[arr[i]]++;
       }
       
       int max = 0 , second_max = 0 ;
       for(auto it = um.begin(); it!= um.end(); it++){
           if(it->second>max){
               second_max = max;
               max = it->second ;
               
              
           }
          else if(it->second>second_max && it->second != max   ){
               second_max = it->second;
              
           }  
            
       }
       for(auto it = um.begin(); it!= um.end(); it++){
           if (it->second == second_max)  ans = it->first;
       }
       return ans;
    }
};

1.1

class Solution {
  public:
    string secFrequent(string arr[], int n) {
      string ans;
      unordered_map < string, int > um;
      for (int i = 0; i < n; i++) {
        um[arr[i]]++;
      }

      int max = 0, second_max = 0;
      string firstMaxFreqString, secondMaxFreqString;
      for (auto it = um.begin(); it != um.end(); it++) {
        int freq = it -> second;

        if (freq > max) {
          second_max = max; //updating seond max freq.
          max = freq; //updating max freq. 

          secondMaxFreqString = firstMaxFreqString; // updating second max freq
          firstMaxFreqString = it -> first; // updating first max freq;

        } else if (freq > second_max && freq != max) {
          second_max = freq;

          secondMaxFreqString = it -> first; //updating second max freq string.
        }

      }

      return secondMaxFreqString;
    }
};

