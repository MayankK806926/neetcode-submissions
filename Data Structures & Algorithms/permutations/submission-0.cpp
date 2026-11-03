class Solution {
public:
    void rec(int ind,auto& nums,auto& ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=ind;i<nums.size();++i){
            swap(nums[i],nums[ind]);
            rec(ind+1,nums,ans);
            swap(nums[i],nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        rec(0,nums,ans);
        return ans;
    }
};
