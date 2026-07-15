class Solution {
public:
    int MOD = 1e9 + 7;
    int findgcd(int a,int b){
        while(b!=0) {
            int rem = a%b;
            a = b;
            b = rem;
        }
        return a;
    }
    // int solve(int i,int seq1,int seq2,vector<int>& nums) {
    //     if(i == nums.size()){
    //         if(seq1 != 0 && seq2 != 0 && seq1 == seq2) return 1;
    //         return 0;
    //     }
    //     if(dp[i][seq1][seq2] != -1) return dp[i][seq1][seq2];
    //     int skip = solve(i+1,seq1,seq2,nums);
    //     int take1 = solve(i+1,findgcd(seq1,nums[i]),seq2,nums);
    //     int take2 = solve(i+1,seq1,findgcd(seq2,nums[i]),nums);
    //     return dp[i][seq1][seq2] = (0LL + skip+take1+take2)%MOD;
    // }   
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0 ; i<n ; i++) {
            if(nums[i]>maxi) maxi = nums[i];
        }
        int dp[n+1][maxi+1][maxi+1];
        for(int i=0 ; i<=maxi ; i++) {
            for(int j=0 ; j<=maxi ; j++) {
                if(i!=0 && j!=0 && i==j) dp[n][i][j] = 1;
                else dp[n][i][j] = 0;
            }
        }
        for(int i=n-1 ; i>= 0 ; i--) {
            for(int j=maxi ; j>=0 ; j--) {
                for(int k=maxi ; k>=0 ; k--) {
                    int skip = dp[i+1][j][k];
                    int take1 = dp[i+1][findgcd(j,nums[i])][k];
                    int take2 = dp[i+1][j][findgcd(k,nums[i])];
                    dp[i][j][k] = (0LL + skip + take1 + take2)%MOD; 
                }
            }
        }
        return dp[0][0][0];
    }
};