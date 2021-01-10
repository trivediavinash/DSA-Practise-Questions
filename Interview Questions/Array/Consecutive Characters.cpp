/*
Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return the power of the string.

 

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
Example 3:

Input: s = "triplepillooooow"
Output: 5
Example 4:

Input: s = "hooraaaaaaaaaaay"
Output: 11
Example 5:

Input: s = "tourist"
Output: 1
 

Constraints:

1 <= s.length <= 500
s contains only lowercase English letters.

*/

1.
class Solution {
public:
    int maxPower(string s) {
        int len= s.length()-1;
        int count =1;
        vector<int> v;
        if(len==0){
            return 1;
        }
        for(int i=0 ;i<len ;i++){
            if(s[i]!=s[i+1]){
                 count=0;
            }
                             
            count++;
        
        
        
            v.push_back(count);
           
        
        }
        return  *max_element(v.begin(),v.end());
      
    }
};



2 .Best Solution

class Solution {
public:
    int maxPower(string s) {
        int len= s.length()-1;
        int c2 =1 , c1 =1 ;
        if(len==0) return 1;
        for(int i=0 ;i<len ;i++){
            if(s[i]==s[i+1])
                c1++;
               
            
            else{
                 c2=max(c2,c1);
                 c1=1;
                
               
            }
             
          c2=max(c2,c1)      ; //case cc ,dd ,ee in this case else statement will never execute and  c2 will not update.
            
           
            
        }
        return c2 ;

    }
};