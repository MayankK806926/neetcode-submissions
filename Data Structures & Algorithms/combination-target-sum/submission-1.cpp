class Solution {
public:
    void rec(int ind,vector<int>& nums,auto& tmp,auto& ans,int target){
        if(target == 0){
            ans.insert(tmp);
            return;
        }
        if(ind > nums.size() - 1) return;

        for(int i=ind;i<nums.size();++i){
            // rec(i+1,nums,tmp,ans,target);
            if(target >= nums[i]){
                tmp.push_back(nums[i]);
                rec(i,nums,tmp,ans,target-nums[i]);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> ans;
        vector<int> tmp;
        rec(0,nums,tmp,ans,target);
        vector<vector<int>> res;
        for(auto& it:ans) res.push_back(it);
        return res;
    }
};
