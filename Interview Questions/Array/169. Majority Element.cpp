/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-231 <= nums[i] <= 231 - 1
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

1. O(N) O(N)


1.1 int majorityElement(vector<int>& nums) {
         unordered_map<int, int> um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }
        for(auto it=um.begin();it!=um.end();++it){
            if(it->second>(nums.size()/2)) return it->first;
        }
        return 0;
    }


1.2 int majorityElement(vector<int>& nums) {
         unordered_map<int, int> um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
            if(um[nums[i]]>nums.size()/2) return nums[i];   /*not a smart move in terms of t.c. as we have to iterate n-1 to find majority elemnt anyhow .expected value of iterations to find N/2-majors turned out to be N-1. In other words, having for example 5000 elements array and 2500 majors in it you still ought to iterate 4999 numbers on average to find all those 2500 majors.  */
        }
        
        return 0;
    } 




2.Boyer-Moore Voting Algorithm  0(N) O(N)  Best Solution

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, major;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                major=nums[i];
            }
            if(major==nums[i]){
                count++;
            }
            else count--;
        }
        return major;
    }
 
};


3. Sorting O(NlogN) O(1)

3.1 class Solution {
     public:
       int majorityElement(vector<int>& nums) {
         int majoritycount=nums.size()/2;
         sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};


3.2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majoritycount=nums.size()/2;
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());  /*t.c. = O(N) Since the majority element appears more than n / 2 times, the n / 2-th element in the sorted nums must be the majority element. In this case, a partial sort by nth_element is enough. */

        return nums[nums.size()/2];
    }
};

4.





