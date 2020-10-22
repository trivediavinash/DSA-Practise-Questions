/*
153. Find Minimum in Rotated Sorted Array
Medium

2681

263

Add to List

Share
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0

*/

1. 8ms o(logn) o(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1){
            return nums[0];
            
        }
      if( nums[0]>nums[n-1] && nums[1]<nums[n-1]){   //case 1  //5 1 2 3 4
            return nums[1];
        } 
         
         //When array is sorted in ascending order 1 2 3 4
        
        if(nums[0]<nums[n-1] and nums[n-1] >nums[n-2]){
            return nums[0];
        }
        
        // When Array is sorted in descening order 4 3 2 1
        if(nums[0]>nums[n-1] and nums[n-1]<nums[n-2]){
            return nums[n-1];
        }
        
        int s=0,e=nums.size()-1  ;     
        while(s<=e){
             int mid=(s+e)/2 ;
            if(nums[mid]<nums[mid+1] and nums[mid]<nums[mid-1]){
                
                 return nums[mid];
            }
            else if(nums[mid]>nums[e] and nums[mid]>nums[0]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return -1;
        
    }
};

2 . 4ms o(logn) o(1)\

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid = l+ (h-l)/2;
            if(nums[mid]>nums[h])
                l=mid+1;
            else if(nums[mid]<nums[h])
                h=mid;
            else
                return nums[mid];
        }
        return -1;
    }
};