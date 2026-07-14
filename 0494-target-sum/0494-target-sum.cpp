class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int total = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total)
            return 0;

        if ((target + total) % 2)
            return 0;

        int req = (target + total) / 2;

        vector<int> dp(req + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int j = req; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[req];
    }
};