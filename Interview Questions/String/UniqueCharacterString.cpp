/*Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.

*/


class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char ,int > m ;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])==m.end()){
                m.insert(make_pair(s[i],1));
                
            }
            else{
                m[s[i]]++;
            }
        }
        for(int i=0;i<s.length();i++){
            if(m[s[i]]==1){
                return i;
            }
        }
        
            
      
        return -1;
    }
};