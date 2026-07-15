class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[201][201][201];
    int findgcd(int a,int b){
        while(b!=0) {
            int rem = a%b;
            a = b;
            b = rem;
        }
        return a;
    }
    int solve(int i,int seq1,int seq2,vector<int>& nums) {
        if(i == nums.size()){
            if(seq1 != 0 && seq2 != 0 && seq1 == seq2) return 1;
            return 0;
        }
        if(dp[i][seq1][seq2] != -1) return dp[i][seq1][seq2];
        int skip = solve(i+1,seq1,seq2,nums);
        int take1 = solve(i+1,findgcd(seq1,nums[i]),seq2,nums);
        int take2 = solve(i+1,seq1,findgcd(seq2,nums[i]),nums);
        return dp[i][seq1][seq2] = (0LL + skip+take1+take2)%MOD;
    }   
public:
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,nums);
    }
};