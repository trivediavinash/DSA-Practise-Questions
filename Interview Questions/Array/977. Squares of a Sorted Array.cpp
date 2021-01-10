/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.

*/

1. o(NlogN)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            v.push_back(nums[i]*nums[i]);
        }
       sort(v.begin(),v.end());
        return v;
    }
};

2. O(N) O(N) 

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans,v1,v2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0) v1.push_back(nums[i]*nums[i]);
            else   v2.push_back(nums[i]*nums[i]);
        }
       
       
       int e1=v1.size()-1, i=e1; int e2 =v2.size(), j=0;
       
        while(i>=0 && j<e2){
            if(v1[i]<v2[j]) {
                ans.push_back(v1[i]);
                i--;
            }
            else {
                 ans.push_back(v2[j]);
                
                j++;
            }
        }
      
        while(j<e2){
            ans.push_back(v2[j]);
            j++;
        }
         while (i >= 0) {
            ans.push_back(v1[i]) ;
             i--;
        
    }
       
        return ans;
    }
};

 
3. O(N)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        
        int i=0, j=n-1;
        for(int k=n-1;k>=0; k--){
            if(abs(nums[i])>abs(nums[j])){
                ans[k]=nums[i]*nums[i];
                i++;
            }
            else{
                ans[k]=nums[j]*nums[j];
                j--;
            }
        }
        return ans;
    }
};