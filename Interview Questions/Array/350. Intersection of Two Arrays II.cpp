/*Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
 

Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?*/

1. T.c. = O(NLogN) + O(MLogM) + O(N) + O(M)  S.c. =O(1)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = (int)nums1.size(), n2 = (int)nums2.size();
        int i1 = 0, i2 = 0;
        vector<int> res;
        while(i1 < n1 && i2 < n2){
            if(nums1[i1] == nums2[i2]) {
                res.push_back(nums1[i1]);
                i1++;
                i2++;
            }
            else if(nums1[i1] > nums2[i2]){
                i2++;
            }
            else{
                i1++;
            }
            while(i1 > 0 && i1 < n1 && nums1[i1] == nums1[i1 - 1]) i1++;  //If elements aree simmilar keep skipping the elemnts.
            while(i2 > 0 && i2 < n2 && nums2[i2] == nums2[i2 - 1]) i2++;
        }
        return res;
    }
};


2.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;
        unordered_map<int, int > um ;
     
        for(int i=0;i<nums1.size();i++){
            um[nums1[i]]++;
        }
        
        for(int i=0; i<nums2.size(); i++){
            if(um[nums2[i]] > 0){          
                res.push_back(nums2[i]);
                um[nums2[i]]--;
            }
        }
        return res;
   
    }
};

