class Solution {
public:
    void rec(int i,vector<int>& nums,auto& tmp,auto& ans,int target){
        if(target == 0){
            ans.push_back(tmp);
            return;
        }
        if(i >= nums.size()) return;

        if(target >= nums[i]){
            tmp.push_back(nums[i]);
            rec(i,nums,tmp,ans,target-nums[i]);
            tmp.pop_back();
        }
        rec(i+1,nums,tmp,ans,target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> tmp;
        rec(0,nums,tmp,ans,target);
        return ans;
    }
};
