/*
Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer. 
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

A slight modification of the problem can be found here.


Example 1:

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{3, 3, 6, 8}. The difference between 
the largest and the smallest is 8-3 = 5.
Example 2:

Input:
K = 3, N = 5
Arr[] = {3, 9, 12, 16, 20}
Output:
11
Explanation:
The array can be modified as
{6, 12, 9, 13, 17}. The difference between 
the largest and the smallest is 17-6 = 11. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function getMinDiff() which takes the arr[], n and k as input parameters and returns an integer denoting the minimum difference.


Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(N)

Constraints
1 ≤ K ≤ 104
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 105

Company Tags
 Adobe Microsoft
*/

1. O(NLogN) O(1)

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        int minn = 0, maxx = 0;
        sort(arr,arr+n);    //sorting the aray as if we want to minimise the heights then we cannot minimise it, one height is sortest and one is tallest as this may be in case of unsorted array .So we sort it so that heights with less height diffrence come together .    
        int res = arr[n-1]-arr[0];  //intially we have assumed our answer to be diffrence betwwen min height and max height.
        
        for(int i=1;i<=n-1;i++){
            if(arr[i]>=k){      //checking if height is atlest k so that we can have positive heights ater add and subtract .  
            maxx = max(arr[i-1]+k , arr[n-1]-k);   //finding max by adding k to smaller element (coz if we want to minimise the heights we have to add k to smaller height and subtract from greater height )   and subbtracting from max element .
            minn = min(arr[i]-k, arr[0]+k);    //subtracting from next consecutive greater height  and adding k in minimum height .
            res = min(res, maxx-minn);    //finally updating our result .
            }
        }
        return res;
    }
       
};
