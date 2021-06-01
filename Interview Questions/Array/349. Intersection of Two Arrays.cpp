/*Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.

*/
/*Complexity Analysis

Time complexity : O(n+m), where n and m are arrays' lengths.O(n) time is used to convert nums1 into set,O(m) time is used to convert nums2, and contains/in operations are O(1) in the average case.

Space complexity : O(m+n) in the worst case when all elements in the arrays are different.*/
1. 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;
        vector<int>v;
        for(int i=0;i<nums1.size();i++){
            s1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            
            s2.insert(nums2[i]);
        }
      for (auto  it = s1.begin(); it != s1.end(); it++){
          if(s2.find(*it )!=s2.end()){
             v.push_back(*it); 
          }
      }
        return v;
    }
    
};

2. Using unoredred_set   O(N) O(N)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) {          /*if(m.erase(a){
                                             res.push_back(a);  //erase funtion will find the element and delete it and if found it will delete element and return true so element a will be pushed.
 
}
                                           */
                res.push_back(a);
                m.erase(a);
            }
        return res;
    }
};


3. T.c. = O(NLogN) + O(MLogM) + O(N) + O(M)  S.c. =O(1)

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

