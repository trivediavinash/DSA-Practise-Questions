/*
Given an array of integers nums, sort the array in ascending order.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
 

Constraints:

1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000

*/

1.Merge Sort
class Solution {
public:
    void merge(vector<int>& nums, int l, int r, int mid){
        vector<int> temp (r-l+1);
        int i = l; // index for left subarray
        int j = m + 1; // index for right subarray
        int k = 0; // index for temporary array
        while(i <= m && j <= r){
            if(nums[i] <= nums[j]) tmp[k++] = nums[i++]; 
            else tmp[k++] = nums[j++];
        }
        while(i <= m) tmp[k++] = nums[i++];
        while(j <= r) tmp[k++] = nums[j++]; 
        for(i = 0; i < k; i++) nums[l + i] = tmp[i];
    }
    }
    void mergesort(vector<int>& nums, int l, int r, int mid ){
        if(l>=r){
            return;  //if elememt is single then it is already sorted or if it is none just return
        }
        int mid=l+(r-l)/2;
        merge(nums, l, mid);
        merge(nums, mid+1, r);
        merge(nums, l, mid, r);
        
    }
        
    vector<int> sortArray(vector<int>& nums) {
         int n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};
