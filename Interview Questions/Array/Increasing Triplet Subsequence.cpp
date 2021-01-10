/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?
*/

1. O(N) O(1)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1=INT_MAX;
        int min2=INT_MAX;
        for(int number:nums){
            if(number<min1) min1=number;
            else if(number>min1 && number<min2) min2=number;
            else if (number>min2) return true;
        }
        return false;
    }
};

2.
/*
first element insert in dp.
if last element of dp is less than current element, push current element in dp.
If current element is less than last element of DP, traverse back in dp to find correct place.
If size of dp is 3, return true
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> dp;
        for(auto n : nums){
            if(dp.size() == 0)
                dp.push_back(n);
            else{
                if(dp.back() < n) dp.push_back(n);
                else {
                    int i = dp.size() - 1;
                    while(i > 0 && dp[i - 1] >= n)i--;
                    dp[i] = n;
                }
            }
            if(dp.size() == 3) return true;
        }
        return false;
    }
};
