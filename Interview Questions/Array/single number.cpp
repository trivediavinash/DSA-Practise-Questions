class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int xorr=0;
        for(auto  x=0;x<nums.size();x++){
            xorr=xorr^nums[x];
            
        }
        return xorr;
    }
};