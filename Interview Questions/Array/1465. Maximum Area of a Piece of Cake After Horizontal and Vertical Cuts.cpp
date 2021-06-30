/*
Given a rectangular cake with height h and width w, and two arrays of integers horizontalCuts and verticalCuts where horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.

Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a huge number, return this modulo 10^9 + 7.

 

Example 1:



Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4 
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.
Example 2:



Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.
Example 3:

Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9
 

Constraints:

2 <= h, w <= 10^9
1 <= horizontalCuts.length < min(h, 10^5)
1 <= verticalCuts.length < min(w, 10^5)
1 <= horizontalCuts[i] < h
1 <= verticalCuts[i] < w
It is guaranteed that all elements in horizontalCuts are distinct.
It is guaranteed that all elements in verticalCuts are distinct.*/


1. O(nlogn) + O(mlogm)

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        horizontalCuts.push_back(h);//adding uppert limit of horizontal cuts    //checking if maximum occurs after the last cut between maxsize length or width
        verticalCuts.push_back(w);//adding uppert limit of vertical cuts
        
       long long horMax = 0;
        for(int i=0; i<horizontalCuts.size(); ++i)
        {
            long long  diff = 0;
            if(i==0)//for index 0, we have max diff as the value of  horizontalCuts[0].
                diff = horizontalCuts[i];
            else
                diff = horizontalCuts[i]- horizontalCuts[i-1];
            horMax = max(diff, horMax);
        }
        long long  verMax = 0;
        for(int i=0; i<verticalCuts.size(); ++i)
        {
            long long  diff = 0;
            if(i==0)//for index 0, we have max diff as the value of  verticalCuts[0].
                diff = verticalCuts[i];
            else
                diff = verticalCuts[i]- verticalCuts[i-1];
            
            verMax = max(diff, verMax);
        }
        return (horMax*verMax) % 1000000007;
    }
};



