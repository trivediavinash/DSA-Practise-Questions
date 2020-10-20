/*
 Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
 

Constraints:

-10^9 <= nums1[i], nums2[i] <= 10^9
nums1.length == m + n
nums2.length == n

*/

1. o(N) o(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=m-1 , b=n-1 ,c=m+n-1;
        
        while(a>=0 and b>=0){
            if(nums1[a]>nums2[b]){
                nums1[c]=nums1[a];
                a--,c--;
                
            }
            else{
                nums1[c]=nums2[b];
                c--,b--;
            }
        }
        //if first array is empty seconf can never be empty.
       while(b>=0){
            nums1[c]=nums2[b];
            c--,b--; 
        } 
    }
};