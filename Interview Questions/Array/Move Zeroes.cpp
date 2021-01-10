/*
iven an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

1. 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int x=nums.size()-1;
        vector<int> v;
        vector<int> v1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                v.push_back(nums[i]);
            }
           else if (nums[i]>0 or nums[i]<0)  v1.push_back(nums[i]);
        }
        v1.insert(v1.end(), v.begin(), v.end());
        nums.clear();
        nums.insert(nums.end(),v1.begin(), v1.end());
        
    }
};

2.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]>0 or nums[j]<0){
                swap(nums[j],nums[i]);
                i++;
            }
            continue;
        }  
    }
};