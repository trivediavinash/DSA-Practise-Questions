class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       
    int cs=0;
    int ms=INT_MIN;
    if(nums.size()==1){
        return nums[0];
    }
	for (int i = 0; i < nums.size(); i++) {
		cs=cs+nums[i];
       
       
        ms=max(cs,ms);
        if(cs<0){
            cs=0;
        }
	}

	return ms;
}
        
        
        
    
    };