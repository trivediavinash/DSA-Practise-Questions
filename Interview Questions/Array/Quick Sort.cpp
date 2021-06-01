// Quick] Sort 


/*Worst Case: The worst case occurs when the partition process always picks greatest or smallest element as pivot. If we consider above partition strategy where last element is always picked as pivot, the worst case would occur when the array is already sorted in increasing or decreasing order. Following is recurrence for worst case. */

/*To do average case analysis, we need to consider all possible permutation of array and calculate time taken by every permutation which doesn’t look easy. */
Average Case:O(nLogn)

/*Best Case: The best case occurs when the partition process always picks the middle element as pivot. Following is recurrence for best case. */

1. //TLE using last elemnt as pivot

class Solution {
public:
    //
    int partition(vector<int>& nums, int left, int right){
            int i=left-1, j=left, pivot=nums[right];
           while(j<right){
                if(nums[j]<pivot){      //First increment the pointer then swap. 
                    i++;
                    swap(nums[i],nums[j]);
                }
               j++;
            }
            swap(nums[i+1],nums[right]);
            return i+1;
        }
    
    
    void quick_sort(vector<int> &nums, int l, int r){
        if(l>=r) return;
        
        int q = partition(nums, l, r);
        quick_sort(nums, l, q-1);
        quick_sort(nums, q+1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size()-1);
        return nums;
    }
};

2. Using first element as pivot

class Solution {
public:
    int partition (vector<int> &nums,int left ,int right) {
    int i = left + 1;
    int piv = nums[left] ; 
    int j =left + 1; //make the first element as pivot element.
    while (j <= right ) {
    /*rearrange the array by putting elements which are less than pivot
       on one side and which are greater that on other. */

          if ( nums[ j ] < piv) {
                 swap (nums[ i ],nums [ j ]);
            i += 1;
        }
        j++;
   }
   swap ( nums[ left ] ,nums[ i-1 ] ) ;  //put the pivot element in its proper place.
   return i-1; 
   
    } 
    
    void quick_sort(vector<int> &nums, int l, int r){
        if(l>=r) return;
        
        int q = partition(nums, l, r);
        quick_sort(nums, l, q-1);
        quick_sort(nums, q+1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size()-1);
        return nums;
    }
};
