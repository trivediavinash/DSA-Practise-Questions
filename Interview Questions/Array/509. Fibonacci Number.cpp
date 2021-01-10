/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).

 

Example 1:

Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
*/

1. Recursive Time complexity : O(2^N) Space complexity : O(N)

class Solution {
public:
    int fib(int N) {
        if(N==0 or N==1){
            return N;
            }
        return  fib(N-1) +fib(N-2);
        
    }
};

2. Recusive +memoization 
class Solution {
public:
    int fib(int N) {
        int memo[N+1];
        memset(dp,0,sizeof(memo));
        if(N<2) return N;
        if(memo[N]!=0) return memo[N];
        return memo[N]= memo(N-1)+memo(N-2);
    }
};

3.Iterative 

class Solution {
public:
    int fib(int N) {
        if(N<2) return N;
        if(N==2) return 1;
        int prev1=1,prev2=1,curr;
        for(int i=3;i<=N;i++){
            curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return curr;
    }
};

4. t.c.=O(N) s.c= O(N)  // Bottom-Up Iterative Dynamic Programming
// O(N) memory
// O(N) time

class Solution {
public:
    int fib(int N) {
       
        if(N<2) return N;
     
        int dp[N+1];
        dp[0]=0,dp[1]=1;
    
        for(int i=2;i<=N;i++){
            dp[i]= dp[i-1]+dp[i-2];
            
        }
       return dp[N];
    }
};