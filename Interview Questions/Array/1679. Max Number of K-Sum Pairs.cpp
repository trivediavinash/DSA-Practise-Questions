/*
You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

 

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109

*/

1. O(NlogN)  O(1)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count=0;
        sort(nums.begin(),nums.end());
        int sz=nums.size();
        int i=0,j=sz-1;
        while(i<j){
            int tot= nums[i]+nums[j];  //compute here so that tc can be improved as we dont have to compute nums[i]+nums[j] again and again;
            if(tot==k){
                count++;
                i++;j--;
            }
            else if (tot>k) j--;
            else i++;
        }
        return count;
    }
};


2. O(N) O(N)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int, int> um;
        for(int n: nums){
            int tot = k-n;     
            if(um[tot]>0){    //checking for frequency of element n+tot =k;
                count++;
                um[tot]--;   //reducing frequency if found
            }
            else {
                um[n]++;
            }
        }
        return count;
    }
};
