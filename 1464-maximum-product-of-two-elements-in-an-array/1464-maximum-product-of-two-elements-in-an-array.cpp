class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1 = 0;
        int maxi2 = -1;
        int n = nums.size();
        for(int i=1 ; i<n ; i++) {
            if(nums[i]>=nums[maxi1]) {
                maxi2 = maxi1;
                maxi1 = i;
            }
            if(maxi2 == -1 && i != maxi1) maxi2 = i;
            if(maxi2 != -1 && nums[i]>nums[maxi2] && i != maxi1) {
                maxi2 = i;
            }
        }
        return (nums[maxi1]-1)*(nums[maxi2]-1);
    }
};