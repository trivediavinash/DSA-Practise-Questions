/*
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

 

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
Example 2:

Input: nums = [6,5,4,8]
Output: [2,1,0,3]
Example 3:

Input: nums = [7,7,7,7]
Output: [0,0,0,0]
 

Constraints:

2 <= nums.length <= 500
0 <= nums[i] <= 100

*/

1.O(n^2) O(1)

class Solution {
  public:
    vector < int > smallerNumbersThanCurrent(vector < int > & nums) {
      vector < int > ans;
      for (int i = 0; i < nums.size(); i++) {
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {
          if (nums[i] > nums[j]) count++;
        }
        ans.push_back(count);
      }
      return ans;
    }
};

2. O(NLogN)  O(N)

/*we have to find no less than the current element so, when we will sort the array, look at the index for eg in this case 8 1 2 2 3 is converted to 1 2 2 3 8 and note down the index of
sorted array, 1 appears at index 0 signifying no less element than one , 8 has index 4 meaning 4 elements are less than that as it is sorted array and now we will store this in map
1 0
2 1
3 3
8 4
*/

class Solution {
  public:
    vector < int > smallerNumbersThanCurrent(vector < int > & nums) {
      unordered_map < int, int > um;
      vector < int > arr = nums; //copying the whole nums array into arr so that we can sort it . 
      sort(arr.begin(), arr.end()); //   sorting the array 
      int n = arr.size();
      for (int i = 0; i < n; i++) {
        if (um.find(arr[i]) == um.end()) um[arr[i]] = i; //counting the frequency of each number of sorted array ,it i also avoiding the duplicates as it will only increase frequency if and only if element is not present in map ,,if it s present it will not increase .
      }
      for (int i = 0; i < n; i++) {
        nums[i] = um[nums[i]]; //copying the frequncy of elemens of nums in arr[i];
      }
      return nums;
    }
};

2.i

/*we have to find no less than the current element so, when we will sort the array, look at the index for eg in this case 8 1 2 2 3 is converted to 1 2 2 3 8 and note down the index of
sorted array, 1 appears at index 0 signifying no less element than one , 8 has index 4 meaning 4 elements are less than that as it is sorted array and now we will store this in map
1 0
2 1
3 3
8 4
*/

class Solution {
  public:
    vector < int > smallerNumbersThanCurrent(vector < int > & nums) {
      unordered_map < int, int > um;
      vector < int > arr = nums; //copying the whole nums array into arr so that we can sort it . 
      sort(arr.begin(), arr.end()); //   sorting the array 
      int n = arr.size();
      for (int i = n - 1; i >= 0; i--) {
        um[arr[i]] = i; // for duplicate cases the map value gets updated with lower value.
        //Here mp[2] initially would be 2 and then again when 2 is encountered the value mp[2] is updated to 1  //  8 1 2 2 4
      }
      for (int i = 0; i < n; i++) {
        nums[i] = um[nums[i]]; //copying the frequncy if elemens of nums in arr[i];
      }
      return nums;
    }
};
