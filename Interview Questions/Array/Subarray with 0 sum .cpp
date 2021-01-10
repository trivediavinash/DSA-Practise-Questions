/*
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
Example 2:

Input:
5
4 2 0 1 6

Output: 
Yes

Explanation: 
0 is one of the element 
in the array so there exist a 
subarray with sum 0.
Your Task:
You only need to complete the function subArrayExists() that takes array and n as parameters and returns true or false depending upon whether there is a subarray present with 0-sum or not. Printing will be taken care by the drivers code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= N <= 104
-105 <= a[i] <= 105

 */

1.// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;


bool subArrayExists(int arr[], int n);
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    	if (subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}// } Driver Code Ends


//Complete this function
bool subArrayExists(int arr[], int n)
{
    
   // create an empty set to store sum of elements of each
	// sub-array A[0..i] where 0 <= i < n
	unordered_set<int> set;

	// insert 0 into set to handle the case when sub-array with
	// 0 sum starts from index 0
	//set.insert(0);

	int sum = 0;

	// traverse the given array
	for (int i = 0; i < n; i++)
	{
		// sum of elements so far
		sum += arr[i];

		// if sum is seen before, we have found a sub-array with 0 sum
		if (sum==0 || set.find(sum) != set.end()) {
			return true;
		} else {
			// insert sum so far into set
			set.insert(sum);
		}
	}

	// we reach here when no sub-array with 0 sum exists
	return false;
}