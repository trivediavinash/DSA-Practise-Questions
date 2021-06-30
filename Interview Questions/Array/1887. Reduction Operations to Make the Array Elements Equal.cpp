/*
Given an integer array nums, your goal is to make all elements in nums equal. To complete one operation, follow these steps:

Find the largest value in nums. Let its index be i (0-indexed) and its value be largest. If there are multiple elements with the largest value, pick the smallest i.
Find the next largest value in nums strictly smaller than largest. Let its value be nextLargest.
Reduce nums[i] to nextLargest.
Return the number of operations to make all elements in nums equal.

 

Example 1:

Input: nums = [5,1,3]
Output: 3
Explanation: It takes 3 operations to make all elements in nums equal:
1. largest = 5 at index 0. nextLargest = 3. Reduce nums[0] to 3. nums = [3,1,3].
2. largest = 3 at index 0. nextLargest = 1. Reduce nums[0] to 1. nums = [1,1,3].
3. largest = 3 at index 2. nextLargest = 1. Reduce nums[2] to 1. nums = [1,1,1].
Example 2:

Input: nums = [1,1,1]
Output: 0
Explanation: All elements in nums are already equal.
Example 3:

Input: nums = [1,1,2,2,3]
Output: 4
Explanation: It takes 4 operations to make all elements in nums equal:
1. largest = 3 at index 4. nextLargest = 2. Reduce nums[4] to 2. nums = [1,1,2,2,2].
2. largest = 2 at index 2. nextLargest = 1. Reduce nums[2] to 1. nums = [1,1,1,2,2].
3. largest = 2 at index 3. nextLargest = 1. Reduce nums[3] to 1. nums = [1,1,1,1,2].
4. largest = 2 at index 4. nextLargest = 1. Reduce nums[4] to 1. nums = [1,1,1,1,1].
 

Constraints:

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 5 * 104*/

1.
class Solution
{
	public:
		int reductionOperations(vector<int> &nums)
		{
			sort(nums.begin(), nums.end());
			int ans = 0, n = nums.size();
			// sort(begin(nums), end(nums));  	//Takes greater time than  sort(nums.begin(), nums.end());  ?????
			for (int i = 1; i < n; i++)
			{
				if (nums[i - 1] < nums[i]) ans += (n - i);
				/*Basically the code is trying to reduce every element that is greater than minimum element to minimum element. Here, (n-i) is nothing but number of elements in array that is greater than the minimum element. So, the result is added with the steps to reduce the array elements(only elements that are currently greater than minimum) to their next smallest element in the array for every iteration until all the elements become the smallest element.

Hope you can better understand the process by below dry-run,
For eg:
Step 1:
0-indexing ------- 0 1 2 3 4 5
Nums         ------  1 1 2 3 4 4
(n-i)=(6-2) =4  elements are greater than current minimum element  (i.e) 2 3 4 4
Assume they are all reduced to their next smallest element(i.e)1 2 3 3
So assume new array is 1 1 1 2 3 3

Step 2:
0-indexing ------- 0 1 2 3 4 5
Nums         ------  1 1 1 2 3 3
(n-i)=(6-3) =3  elements are greater than minimum element (3) (i.e)2 3 3
Assume they are all reduced to their next smallest element again (i.e)1 2 2
So assume new array is 1 1 1 1 2 2

Step 3:
0-indexing ------- 1 2 3 4 5 6
Nums         ------  1 1 1 1 2 2
(n-i)=(6-2) =2  elements are greater than minimum element (2) (i.e) 2 2
Assume they are all reduced to their next smallest element again(i.e)1 1
So assume new array is 1 1 1 1 1 1

So,all elements will be reduced to minimum element and adding all (n-i) values throughout the iteration we get 4+3+2=9 steps which is the cost to make all the array elements equal abiding by the given rules.*/
			}
			return ans;
		}
};
