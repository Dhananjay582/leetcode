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
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0 ; i<n ; i++) {
            if(nums[i]>maxi) maxi = nums[i];
        }
        vector<vector<int>> prev(maxi+1,vector<int> (maxi+1,0));
        vector<vector<int>> curr(maxi+1,vector<int> (maxi+1,0));
        for(int i=0 ; i<=maxi ; i++) {
            for(int j=0 ; j<=maxi ; j++) {
                if(i!=0 && j!=0 && i==j) prev[i][j] = 1;
                else prev[i][j] = 0;
            }
        }
        for(int i=n-1 ; i>= 0 ; i--) {
            for(int j=maxi ; j>=0 ; j--) {
                for(int k=maxi ; k>=0 ; k--) {
                    int skip = prev[j][k];
                    int take1 = prev[findgcd(j,nums[i])][k];
                    int take2 = prev[j][findgcd(k,nums[i])];
                    curr[j][k] = (0LL + skip + take1 + take2)%MOD; 
                }
            }
            prev = curr;
        }
        return prev[0][0];
    }
};