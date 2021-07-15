/*
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6
 

Constraints:

3 <= nums.length <= 104
-1000 <= nums[i] <= 1000
*/

/*
lets consider 2 cases
1. when all are positive or negative ans is product of last three numbers in sorted array
2. when two negative no and one postive no (largest) will give ans 
3. 
*/
1. O(NLogN)  O(1)
 class Solution {
  public:
    int maximumProduct(vector < int > & nums) {
      int n = nums.size();

      sort(nums.begin(), nums.end());

      return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};
//we just need to find the 3 largest elements and 2 min elements
2. O(N) O(1)

class Solution {
  public:
    int maximumProduct(vector < int > & nums) {
      int n = nums.size();
      int min1 = INT_MAX, min2 = INT_MAX;
      int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
      for (int n: nums) {
        if (n <= min1) {
          min2 = min1;
          min1 = n;
        } else if (n <= min2) { // n lies between min1 and min2
          min2 = n;
        }
        if (n >= max1) { // n is greater than max1, max2 and max3
          max3 = max2;
          max2 = max1;
          max1 = n;
        } else if (n >= max2) { // n lies betweeen max1 and max2
          max3 = max2;
          max2 = n;
        } else if (n >= max3) { // n lies betwen max2 and max3
          max3 = n;
        }
      }
      return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
