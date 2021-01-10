/*
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output: 6
Explanation: The consecutive numbers 
here are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output: 4
Explanation: 1, 2, 3, 4 is the longest
consecutive subsequence.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findLongestConseqSubseq() which takes the array arr[] and the size of the array as inputs and returns the length of the longest subsequence of consecutive integers. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
0 <= a[i] <= 105

*/

1. tc=o(n)  sc= o(nlogn)

int findLongestConseqSubseq(int arr[], int N)
{   
    set<int>s;
    
    for(int i=0;i<N;i++){
        s.insert(arr[i]);
    }
    int count =1,res=0;
    for(auto i:s){
        if(s.find(i+1)!=s.end()) count++;
        else{
            res=max(count,res);
            count=1;
        }
        
    }
    res=max(res,count);  //if all elements are sorted; 1 2 3 4 5 or corner cases like if one ele is longest .
    
    return res;

}

2. 
Time complexity : O(nlgn).

The main for loop does constant work nn times, so the algorithm's time complexity is dominated by the invocation of sort, which will run in O(nlgn) time for any sensible implementation.

Space complexity : O(1) or O(n).

For the implementations provided here, the space complexity is constant because we sort the input array in place. If we are not allowed to modify the input array, we must spend linear space to store a sorted copy.

int findLongestConseqSubseq(int arr[], int N)
{   
    sort(arr,arr+N);
    int count=1,res=0;
    for(int i=1;i<N;i++){
        if(arr[i]-arr[i-1]==1){
            count++;
            res=max(count,res);
        }
        else if(arr[i]==arr[i-1]){
            continue;
        }
        if(arr[i]-arr[i-1]>1){
            count=1;
            
            
        }
       
    }
    res=max(count,res);  // for corner case like if length of longest consecutive element is 1  .
    return res;

}

3.   o(N) o(N) 
int findLongestConseqSubseq(int arr[], int N)
{   
    //int N= nums.size(); 
        if(N==0 or N==1) return N;
       unordered_set<int>s;
    
         for(int i=0;i<N;i++){
            s.insert(arr[i]);
         }
       int count, longest_streak=0,current_num;
        for(auto i:s){
             
            if(!s.count(i-1)){     // If i-1 exits do nothing ,if not exist search for i+1 and count . we can also check for i+1 simmilarly.
                current_num = i;
                 count=1;
           
            while(s.count(current_num+1)){
                current_num++;
                count++;
            }

          longest_streak=max(longest_streak,count);
        }
      }
       
        return longest_streak;

}





















