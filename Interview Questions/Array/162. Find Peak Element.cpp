/*
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 

Constraints:

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
nums[i] != nums[i + 1] for all valid i.
*/

1.O(N) O(1)

class Solution {
public:
    /* consider 4 cases for checking peak 
     1.  1,2,3  peak = 3
     2.  3,2,1  peak =3
     3.  1,3,2  peak = 3
     4.  2,3,1  peak = 3
     (1 2 2  // 2 2 1)  not valid as nums[i] != nums[i + 1] for all valid i.
    */
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;  //if only one element thrn there is no peak element
        for(int i = 0 ;i<n-1;i++){
            if(nums[i]>nums[i+1]) return i;      
        }
        return n-1;  //if nums is sorted in increasing order
    }
};

2. O(LogN) O(1)

class Solution {
  public:
    int findPeakElement(vector < int > & nums) {
      int n = nums.size();
      if (n == 1) return 0; //if only one element thrn there is no peak element

      int s = 0, e = nums.size() - 1;
      while (s <= e) {
        int mid = s + (e - s) / 2;
        if (mid > 0 && mid < n - 1) { //if mid is not at the last index or first index then continue;
          if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
            return mid;
            break;
          } else if (nums[mid] > nums[mid - 1]) s = mid + 1;   // suppose nums to be 1 2 4 3 mid will element 2 so comparing with mid-1 it is more firmed that our ans will be in right half as mid is already greater than mid-1 in left there cant be our ans as peak. 
          else e = mid - 1;
        } else if (mid == 0) { //else mid is the first element then check it with the only one neighbour right of it (may be in case of sorted array in decreasing prder)
          if (nums[mid] > nums[mid + 1]) return 0; //if it is greater than its right element than return it else return mid->right
          else return 1;
        } else if (mid == n - 1) { // if mid is last elemnt then check it  may be in sorted array in increasing order
          if (nums[mid] > nums[mid - 1]) return n - 1;
          else return n - 2;
        }
      }
      return -1;
    }
};


2.1

class Solution {
  public:
    /* consider 4 cases for checking peak 
     1.  1,2,3  peak = 3
     2.  3,2,1  peak =3
     3.  1,3,2  peak = 3
     4.  2,3,1  peak = 3
     (1 2 2  // 2 2 1)  not valid as nums[i] != nums[i + 1] for all valid i.
    */
    int findPeakElement(vector < int > & nums) {
      int n = nums.size();
      if (n == 1) return 0; //if only one element thrn there is no peak element

      // check if 0th/n-1th index is the peak element in case of sorted array
      if (nums[0] > nums[1]) return 0;
      if (nums[n - 1] > nums[n - 2]) return n - 1;

      // search in the remaining array ignoring first and last elemnts as we have already chechked and if first and last indes is not the answer than we don not to worry about chechking them as out ans so no need to consider them .
      int start = 1;
      int end = n - 2;

      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid; //still it may check here  for first and last index here 
        else if (nums[mid] < nums[mid - 1]) end = mid - 1;
        else if (nums[mid] > nums[mid - 1]) start = mid + 1; //alternatively only else start = mid+1 will work
      }
      return -1; // dummy return statement

    }
};

/* kval ek hi peak nhi hai jayad bhi ho sakti hai so jidhar slope increase ho rha hai udhar jaao bs aue jaise hi decrease ho slope return kr do
Most people have figured out the binary search solution but are not able to understand how its working. I will try to explain it simply. What we are essentially doing is going in the direction of the rising slope(by choosing the element which is greater than current). How does that guarantee the result? Think about it, there are 2 possibilities.a) rising slope has to keep rising till end of the array b) rising slope will encounter a lesser element and go down.
In both scenarios we will have an answer. In a) the answer is the end element because we take the boundary as -INFINITY b) the answer is the largest element before the slope falls. Hope this makes things clearer.
*/
