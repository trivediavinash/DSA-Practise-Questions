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


3. Randomized Quicksort

class Solution {
public:
    //
    int partition(vector<int>& nums, int left, int right){
          int i=left-1, j=left;
          int random = left + rand() % (right - left);
           swap(nums[right], nums[random]);
          int pivot=nums[right];
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

4. Reducing worst space space to logN using tail call optimization. Merge sort is tail call recursion.

/*We have discussed (in tail recursion) that a recursive function is tail recursive if the recursive call is the last thing executed by the function. 

C++

// An example of tail recursive function
void print(int n)
{
    if (n < 0) 
       return;
    cout << " " << n;
 
    // The last executed statement is recursive call
    print(n-1);
}*/ 


/*
Function stack frame management in Tail Call Elimination : 
Recursion uses a stack to keep track of function calls. With every function call, a new frame is pushed onto the stack which contains local variables and data of that call. Let’s say one stack frame requires O(1) i.e, constant memory space, then for N recursive call memory required would be O(N). 

Tail call elimination reduces the space complexity of recursion from O(N) to O(1). As function call is eliminated, no new stack frames are created and the function is executed in constant memory space. 

It is possible for the function to execute in constant memory space because, in tail recursive function, there are no statements after call statement so preserving state and frame of parent function is not required. Child function is called and finishes immediately, it doesn’t have to return control back to the parent function. 

As no computation is performed on the returned value and no statements are left for execution, the current frame can be modified as per the requirements of the current function call. So there is no need to preserve stack frames of previous function calls and function executes in constant memory space. This makes tail recursion faster and memory-friendly.*/



class Solution {
public:
    //
    int partition(vector<int>& nums, int left, int right){
          int i=left-1, j=left;
          int random = left + rand() % (right - left);
           swap(nums[right], nums[random]);
          int pivot=nums[right];
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
        while(l<r){
        int pi = partition(nums, l, r);
            // If left part is smaller, then recur for left
        // part and handle right part iteratively
        if (pi - l < r - pi)
        {    
            quick_sort(nums, l, pi - 1);
            l = pi + 1;
        }
 
        // Else recur for right part
        else
        {
            quick_sort(nums, pi + 1, r);
            r = pi - 1;
        }
            
            
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size()-1);
        return nums;
    }
};


//In the above code, if left part becomes smaller, then we make recursive call for left part. Else for the right part. In worst case (for space), when both parts are of equal sizes in all recursive calls, we use O(Log n) extra space. 



