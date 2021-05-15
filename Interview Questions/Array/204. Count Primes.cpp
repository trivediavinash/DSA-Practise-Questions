/*
Count the number of prime numbers less than a non-negative number, n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106
*/

1. 
/*
Let's write down all of 12's factors:

2 × 6 = 12
3 × 4 = 12
4 × 3 = 12
6 × 2 = 12
As you can see, calculations of 4 × 3 and 6 × 2 are not necessary. Therefore, we only need to consider factors up to √n because, if n is divisible by some number p, then n = p × q and since p ≤ q, we could derive that p ≤ √n.

Our total runtime has now improved to O(n1.5)
*/

class Solution {
private:
    bool checkfactors(int num){
        for(int i=2;i*i<=num;i++){
            if(num%i==0) return false ;     // Loop's ending condition is i * i <= num instead of i <= sqrt(num)
   // to avoid repeatedly calling an expensive function sqrt().
            
        }
        return true;
    }
public:
    int countPrimes(int n) {
        int count=0;
        if(n==1 or n==0) return 0;
        for(int i=1;i<n;i++){
            if(checkfactors(i)) count++;    
        }
        return count-1;
    }
};



2.


