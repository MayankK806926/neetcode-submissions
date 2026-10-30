class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n-1;
        int ans = 0;
        while(l < r){
            int val = (r-l) * min(heights[l],heights[r]);
            ans = max(ans,val);
            if(heights[l] < heights[r]) l++;
            else r--;
        }

        return ans;
    }
};
