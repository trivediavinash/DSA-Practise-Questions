class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int e=arr.size()-1;
        int s=0;
      
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1]){
               return mid;
            }
            else if(arr[mid]<arr[mid+1]){
                s=mid+1;
                
            }
            else{
                e=mid;
            }
        }
        
       return -1;
        
    }
};