/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

*/
//back() will retern refernce to last element of vector
1. O(NLogN) O(1) or  O(Logn)

class Solution {
  public:
    vector < vector < int >> merge(vector < vector < int >> & intervals) {
      vector < vector < int >> ans;
      sort(intervals.begin(), intervals.end());
      if (intervals.size() == 1) return intervals;
      ans.push_back(intervals[0]); //pushed first interval for comparing 

      int n = intervals.size();
      for (int i = 1; i < n; i++) { //starting from second interval  
        if (ans.back()[1] >= intervals[i][0]) { //comparing end of already pushed most recent interval with the strat of current interval .      
          ans.back()[1] = max(ans.back()[1], intervals[i][1]); //if end of already pushed most recent interval is equal or greater than the current start point of interval take max of it so that both the end can be accomodate .
        } else ans.push_back(intervals[i]);
      }
      return ans;
    }
};
