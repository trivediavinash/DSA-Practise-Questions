/*
Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

 

Example 1:

Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
 

Note:

1 <= S.length <= 20000
S consists only of English lowercase letters.
*/

tc=0(N), oc=o(n)
1.class Solution {
public:
    string removeDuplicates(string S) {
         string ans;
         if(S.size()==1) return S;
        for(int i=0;i<S.size();i++){
            if(ans.size()>0 && S[i]==ans[ans.size()-1]) {
                ans.pop_back();
               //ans.pop_back();
                continue;
            }
            ans.push_back(S[i]);
        }
        return ans;
    }
};



2. Using Stack ..Expensive 
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char>s;
        string ans;
        if(S.size()==1) return S;
        for(int i=0;i<S.size();i++){
           /* if(s.empty()){
                s.push(S[i]);
                continue;
            } */
            if(s.size()>0 && S[i]==s.top()) {
                s.pop();
               //ans.pop_back();
                continue;
            }
            s.push(S[i]);
        }
        while(!s.empty()){
            ans=s.top()+ans;
            s.pop();
        }
        return ans;
    }
};

