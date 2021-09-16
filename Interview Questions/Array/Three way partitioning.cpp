/*
Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.


Example 1:

Input: 
n = 5
A[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
Output: 1
Explanation: One possible arrangement is:
{1, 2, 3, 3, 4}. If you return a valid
arrangement, output will be 1.


Example 2:

Input: 
n = 3 
A[] = {1, 2, 3}
[a, b] = [1, 3]
Output: 1
Explanation: One possible arrangement 
is: {1, 2, 3}. If you return a valid
arrangement, output will be 1.


Your Task:
You dont need to read input or print anything. The task is to complete the function threeWayPartition() which takes the array[], a and b as input parameters and modifies the array in-place according to the given conditions.
Note: The generated output is 1 if you modify the given array successfully.


Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)


Constraints:
1 <= n <= 106
1 <= A[i] <= 106

Company Tags
 Yahoo
*/

1. sorting nlogn 
class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here 
        sort(array.begin(), array.end());
        
    }
};

2. O(N) O(1)

class Solution
{
	public:
		//Function to partition the array around the range such 
		//that array is divided into three parts.
		void threeWayPartition(vector<int> &array, int a, int b)
		{
			// code here 
			//start to low-1 will be region of lesser( < a)
			//low to mid-1 will be region of ..in between(a,b)
			// mid to high will be unknown region as we dont know who will be here and we are only exhausting this region by checking for lesser( < a) in between(a,b) and greater(>b)
			//hight+1 to end will be region of greater(>b)

			int low = 0;
			int mid = 0;
			int high = array.size() - 1;
			while (mid <= high)
			{
				if (array[mid] < a)
				{
					swap(array[mid], array[low]);
					//  here we are confirmed that elements in between A  && B  will at bw low to mid-1 so we increase mid
					mid++;
					// here we are confirmed that elements lesser than A will at behind the low so we increase low
					low++;
				}
				else if (array[mid] > b)
				{
					swap(array[mid], array[high]);
					//region of >b grows from the back 
					high--;	//// here we are confirmed that elements which we have cheked at mid index is >b so be swap them and decrease high pointer as high is gaurenteed >b .

				}
				else
				{
					mid++;	// regon of in between(a,b)

				}
			}
		}
};
