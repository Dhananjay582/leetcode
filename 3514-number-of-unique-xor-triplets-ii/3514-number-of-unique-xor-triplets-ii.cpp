class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int k = 1;
        while(k<=maxi){
            k *= 2;
        }
        vector<int> xorOf2(k+1,0);
        for(int i=0 ; i<n ; i++) {
            for(int j=i ; j<n ; j++) {
                xorOf2[(nums[i]^nums[j])] = 1;
            }
        }
        vector<int> xors(k+1,0);
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<=k ; j++) {
                if(xorOf2[j] == 1) {
                    xors[j^nums[i]] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i=0 ; i<=k ; i++) {
            if(xors[i] == 1) cnt++;
        }
        return cnt;
    }
};