class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r){
            int val = nums[l] + nums[r];
            if(val == target){
                return {l+1,r+1};
            }else if(val < target){
                l++;
            }else r--;
        }
        return {-1,-1};
    }
};
