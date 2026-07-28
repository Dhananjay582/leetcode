class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        vector<int> cnt(26,0);
        for(int i=0 ; i<n/2 ; i++) {
            cnt[s[i]-'a']++;
        }
        string ans = "";
        for(int i=0 ; i<26 ; i++) {
            if(cnt[i]>0) {
                ans += string(cnt[i],i+'a');
            }
        }
        if(n%2 == 1) ans += s[n/2];
        for(int i=25 ; i>=0 ; i--){
            if(cnt[i]>0) {
                ans += string(cnt[i],i+'a');
            }
        }
        return ans;
    }
};