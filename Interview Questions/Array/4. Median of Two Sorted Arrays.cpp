/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

1. O(nLogn + mLogM)     O(M+N);

class Solution
{
	public:
		double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
		{

			int m = nums1.size(), n = nums2.size();

			vector<int> v(nums1);	//copying both vectors into single vectors
			for (auto x: nums2)
			{
				v.push_back(x);
			}

			sort(v.begin(), v.end());

			if (v.size() % 2 == 0) return double(v[(v.size() / 2) - 1] + v[(v.size() / 2)]) / 2;	//for even median = (mid + (mid-1))/2
			else return v[v.size() / 2];	//for odd median  = mid
		}
};

2.  O(N+M)  O(N+M)

class Solution
{
	public:
		double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
		{

			int m = nums1.size(), n = nums2.size();
			int i = 0, j = 0;
			vector<int> v;
			/merging two sorted array
			while (i < m && j < n)
			{
				if (nums1[i] > nums2[j])
				{
					v.push_back(nums2[j]);
					j++;
				}
				else
				{
					v.push_back(nums1[i]);
					i++;
				}
			}
			while (i < m)
			{
				v.push_back(nums1[i]);
				i++;
			}
			while (j < n)
			{
				v.push_back(nums2[j]);
				j++;
			}

			if (v.size() % 2 == 0) return double(v[(v.size() / 2) - 1] + v[(v.size() / 2)]) / 2.0;	//for even 
			return v[v.size() / 2];	//for odd 
		}
};

3.  O(N+M)  O(1)

class Solution
{
	public:
		double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
		{

			double median, prev;
			int nums1Size = nums1.size(), nums2Size = nums2.size();
			int mid = (nums1Size + nums2Size) / 2;
			for (int i = 0, j = 0;;)
			{
				if (j == nums2Size)
				{
					//if nums2 is of size 0;
					median = nums1[i++];
				}
				else if (i == nums1Size)
				{
					// if nums1 is of size 0;
					median = nums2[j++];
				}
				else if (nums1[i] < nums2[j])
				{
					median = nums1[i++];
				}
				else
				{
					median = nums2[j++];
				}
				if (i + j > mid)
				{
					//checking if i+j has crossed the mid of merged array 
					if ((nums1Size + nums2Size) % 2 == 0)
					{
						//if even 
						median = (prev + median) / 2;
					}
					return median;	//if odd
				}
				prev = median;	//updating median 
			}
		}
};


4 . 
