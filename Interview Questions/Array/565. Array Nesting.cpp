/*
You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].

You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:

The first element in s[k] starts with the selection of the element nums[k] of index = k.
The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
We stop adding right before a duplicate element occurs in s[k].
Return the longest length of a set s[k].

 

Example 1:

Input: nums = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
nums[0] = 5, nums[1] = 4, nums[2] = 0, nums[3] = 3, nums[4] = 1, nums[5] = 6, nums[6] = 2.
One of the longest sets s[k]:
s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}
Example 2:

Input: nums = [0,1,2]
Output: 1
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] < nums.length
All the values of nums are unique.

*/

O(N^2) O(1)

// there will be cycles formed for each index ..we have to find maximum lenght from all the cycles
class Solution
{
	public:
		int arrayNesting(vector<int> &nums)
		{
			int n = nums.size();
			int ans = 0;
			for (int i = 0; i < n; i++)
			{

				int start = nums[i];	// making every number in nums as strating point for loop formed
				int count = 0;
				do { 	start = nums[start];	//update the numbers accordingly 
					count++;
				}
				while (start != nums[i]);	//here nums[i] will be the starting point of loop means our current number in outer loop

				ans = max(ans, count);	//ans will be maximum from all the cycles 

			}
			return ans;
		}
};

2. O(N) O(N) 

class Solution
{
	public:
		int arrayNesting(vector<int> &nums)
		{

			int n = nums.size();
			vector<int> visited(n, 0);	//keeping visitd array to avoid repititive calcultions like if we have considered one element in cycle, it means every element in  that cycle will have the same cycle 
			//so we will mark visited current elemnt of cycle visisted and it will not be considered as the starting point for any cycles hence avoiding repetitive calculations 

			//5,4,0,3,1,6,2]
			// in this case element 0,2 ,5 6 will have same cycle 

			int ans = 0;
			for (int i = 0; i < n; i++)
			{
				if (!visited[i])
				{
					int start = nums[i];
					int count = 0;
					do {

						count++;
						visited[start] = true;  //marking second elemnt of first occured cycle to true 
						start = nums[start];
					}
					while (start != nums[i]);

					ans = max(ans, count);
				}
			}
			return ans;
		}
};

3.O(N) O(1)

class Solution
{
	public:
		int arrayNesting(vector<int> &nums)
		{

			int n = nums.size();

			//keeping visitd array to avoid repititive calcultions like if we have considered one element in cycle, it means every element in  that cycle will have the same cycle 
			//so we will mark visited current elemnt of cycle visisted and it will not be considered as the starting point for any cycles hence avoiding repetitive calculations 

			//5,4,0,3,1,6,2]
			// in this case element 0,2 ,5 6 will have same cycle 

			//here we have eliminated extra array and marking the element in nums it self to some value as visited 
			int ans = 0;
			for (int i = 0; i < n; i++)
			{
				if (nums[i] != INT_MAX)
				{
					int start = nums[i];
					int count = 0;
					while (nums[start] != INT_MAX)
					{
					 			//before marking to visited update the values accordingly 

						int temp = start;
						start = nums[start];
						count++;
						nums[temp] = INT_MAX;
					}

					ans = max(ans, count);
				}
			}
			return ans;
		}
};
