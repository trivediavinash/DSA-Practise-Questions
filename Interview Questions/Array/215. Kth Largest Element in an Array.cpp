/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 104
-104 <= nums[i] <= 104
*/

//1. O(NlogN) O(N)

//Priority queue stores element according to some priority stl priority queue is implemented as max heap (max elemnt will will be at top) .
//1.push all elements into heap
//2.pop one by one untill k==0 and return top most elemnt after k operation of pop

class Solution {
  public:
    int findKthLargest(vector < int > & nums, int k) {
      priority_queue < int > pq;
      int n = nums.size();
      int prev = INT_MAX;
      //crating heap takes O(N) + inserting takes O(logN) heapify = O(NlogN)  
      for (int i = 0; i < n; i++) {
        if (prev != nums[i]) pq.push(nums[i]); //To avoid duplicates in the array.
      }
      k--;
      // O(NLogN)
      while (!pq.empty()) {
        if (k == 0) return pq.top();
        pq.top();
        pq.pop();
        k--;

      }
      return 0;
    }
};

2. O(NlogK) O(k)
// we have N elements and pushing them into max heap , pushing operation will take logK time and N elements will be pushed in N time.
//since we are using priority queue of size k only so space complexity will be O(k).
//NOTE  - if asked to find k largest use min heap as in min heap min element will always be at the top and it will get pop out and finally left with largest element in the queue and   using max heap will cost extra complexity .
//if asked to find k smallest element use max heap as minumum element will always be at bottom of priority queue. 

class Solution {
  public:
    int findKthLargest(vector < int > & nums, int k) {
      priority_queue < int > pq;   //maxheap
      int n = nums.size(); 

      for (int i = 0; i < n; i++) { 
        pq.push(nums[i] * (-1));      //multiplying by (-1) so that max number get opposite priority.
        if (pq.size() > k) pq.pop();
      }

      return pq.top() * (-1);  
    }
};
3. O(NlogK) O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int> > pq;   //min heap
        int n = nums.size();
       
        for(int i = 0 ;i<n ;i++){
              pq.push(nums[i]);
              if(pq.size()>k) pq.pop();     //pq will have at most k elements always
        }
       
        return pq.top();
    }
};
3. O(NlogN) O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};





4.Worst-case performance	О(n2) -  1 2 3 4 5 finding 5th largest 
Best-case performance	О(n)    n + n/2 + n/4 + n/8 = n(1+ 1/2 + 1/4 ) = n 
Average performance	O(n)

Quicselect Algo (Lomuto partitioning with or without randomisation ) (Randomisation is very fast )


// In lomuto partitioning while partitioning, element smaller than pivot chhosen as rightmost element, are arranges in left of pivot and elemetns greater than pivot always comes in right  .so it will be usefull to directly compare k with finding kth smallest element .
//In case of finding largest element k should be modified so that our partitioning indx can be matched .k = size - k . 

class Solution {
  int lomutoPartition(vector < int > & nums, int left, int right) {
    int i = left - 1, j = left;
    //we can also use randomized partion .
    // int randomIdx = left+ rand()%(right-left+1);   //genarting random indices using rand funtion   
    //  swap(nums[randomIdx], nums[right]);
    int pivot = nums[right];
    while (j < right) {
      if (nums[j] <= pivot) {
        i++;
        swap(nums[i], nums[j]);
      }
      j++;
    }
    swap(nums[i + 1], nums[right]);
    return i + 1;
  }

  //searching the kth element by index like kth largest element will have k-1 index in sorted array (in decresing order) 4 3 2 1 2nd largest is 3 
  //since in lumuto partitioning larger elements are in right part so we have to modify the k value as pos = nums.size()-k; partition funtion is calling in only half part always .
  public:
    int findKthLargest(vector < int > & nums, int k) {
      int left = 0, right = nums.size() - 1, pos = nums.size() - k;
      while (true) {
        int idx = lomutoPartition(nums, left, right);
        if (idx == pos) {
          return nums[pos];
          break;
        } else if (idx < pos - 1) left = idx + 1;
        else if (idx > pos - 1) right = idx - 1;

      }
      return 0;
    }
};


 
