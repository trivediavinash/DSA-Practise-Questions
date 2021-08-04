/*
Write a function that reverses a string. The input string is given as an array of characters s.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
 

Follow up: Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/

1. Recursive O(N) O(N) recursive stack

class Solution
{
	public:
		void helper(vector<char> &s, int left, int right)
		{
			if (left >= right) return;	//for even size left == right will never come, so left >= right conditio should be there 
			char temp = s[left];	//Swapping 
			s[left] = s[right];
			s[right] = temp;
			left++, right--;	// increasing  decreasing the left and right pointer for next call
			helper(s, left, right);	//calling funtion to itself for smaller input
		}

	public:
		void reverseString(vector<char> &s)
		{
			helper(s, 0, s.size() - 1);
		}
};

2.  O(N/2) O(1)

class Solution
{
	public:
		void reverseString(vector<char> &s)
		{
			//int l=0;
			int e = s.size();
			int mid = e / 2;
			for (int i = 0; i < mid; i++)
			{
				swap(s[i], s[e - i - 1]);
			}
		}
};

3. O(N) O(1)
class Solution
{

	public:
		void reverseString(vector<char> &s)
		{
			int left = 0, right = s.size() - 1;
			while (left < right)
			{
				char temp = s[left];
				s[left] = s[right];
				s[right] = temp;
				left++, right--;
			}
		}
};
