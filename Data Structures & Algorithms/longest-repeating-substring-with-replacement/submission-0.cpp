class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0,r = 0;
        int ans = 0;
        vector<int> hsh(26);
        int mxFreq = 0;

        while(r < n){
            hsh[s[r]-'A']++;
            mxFreq = max(mxFreq, hsh[s[r]-'A']);

            while(l < r && ((r-l+1) - mxFreq) > k){
                hsh[s[l]-'A']--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;      
    }
};