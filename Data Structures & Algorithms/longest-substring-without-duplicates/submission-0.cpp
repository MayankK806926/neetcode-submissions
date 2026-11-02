class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0,r = 0;
        unordered_map<char,int> mpp;
        int ans = 0;
        while(r < n){
            mpp[s[r]]++;

            while(l<r && mpp[s[r]] > 1){
                mpp[s[l]]--;
                l++;
            }

            ans = max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};
