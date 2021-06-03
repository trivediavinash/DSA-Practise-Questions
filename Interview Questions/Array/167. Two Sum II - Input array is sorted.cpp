/*
Given an array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.

Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
 

Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.*/

1. O(NLogN) O(1)

/*
Say, fix the first element A[0] and do binary search on the remaining n-1 elements. If cannot find any element which equals target-A[0], Try A[1]. That is, fix A[1] and do binary search on A[2]~A[n-1]. Continue this process until we have the last two elements A[n-2] and A[n-1].

Does this gives a time complexity lg(n-1) + lg(n-2) + ... + lg(1) ~ O(lg(n!)) ~ O(nlgn).*/ 

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    if(numbers.empty()) return {};
    for(int i=0; i<numbers.size()-1; i++) {
        int start=i+1, end=numbers.size()-1, gap=target-numbers[i];
        while(start <= end) {
            int m = start+(end-start)/2;
            if(numbers[m] == gap) return {i+1,m+1};
            else if(numbers[m] > gap) end=m-1;
            else start=m+1;
        }
    }
        return{};
}
      
        
       
};



2. O(N) O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int i=0; 
        int j=numbers.size()-1;
        while(i<j ){
            int tot=numbers[i]+numbers[j];
            if( tot == target) {
                ans.push_back(i+1);
                ans.push_back(j+1);
                
                break;
            }
            else if( tot > target){
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
