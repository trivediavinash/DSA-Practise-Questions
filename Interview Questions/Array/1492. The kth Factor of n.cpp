/*

Given two positive integers n and k.

A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.

 

Example 1:

Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
Example 2:

Input: n = 7, k = 2
Output: 7
Explanation: Factors list is [1, 7], the 2nd factor is 7.
Example 3:

Input: n = 4, k = 4
Output: -1
Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should return -1.
Example 4:

Input: n = 1, k = 1
Output: 1
Explanation: Factors list is [1], the 1st factor is 1.
Example 5:

Input: n = 1000, k = 3
Output: 4
Explanation: Factors list is [1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100, 125, 200, 250, 500, 1000].
 

Constraints:

1 <= k <= n <= 1000
*/

1. 
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++){
            if(n%i==0) v.push_back(i);
           
        }
         if(k>v.size()){
            return -1;
         }
       return v[k-1];
    }
};

2.

class Solution {
public:
    int kthFactor(int n, int k) {
     
        for(int i=1;i<=n;i++){
            if(n%i==0){
                k--;
            }
            if(k==0) return i;
        }
        return -1;
    }
};

3. O(sqrt)

class Solution {
public:
    int kthFactor(int n, int k) {
    int d = 1;
    for ( ; d * d <= n; ++d)
        if (n % d == 0 && --k == 0)
            return d;
    /*note that
    for (d = d - 1; d >= 1; --d)
    helps iteration to new factors in sorted fashion.    */
    for ( d = d - 1; d >= 1; --d) {
        if (d * d == n)     //skipping d*d coz divisor would already be accounted for in the first for loop.
           continue;
        if (n % d == 0 && --k == 0)
            return n / d;
    }
    return -1;

    }
};