class Solution {
public:
    void rec(int ind,auto& nums,auto& tmp,auto& ans,int tar){
        if(tar == 0){
            ans.push_back(tmp);
            return;
        }
        if(ind == nums.size()) return;

        if(tar >= nums[ind]){
            tmp.push_back(nums[ind]);
            rec(ind+1,nums,tmp,ans,tar-nums[ind]);
            tmp.pop_back();
        }
        while(ind+1 < nums.size() && nums[ind+1] == nums[ind]){
            ind++;
        }
        rec(ind+1,nums,tmp,ans,tar);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        rec(0,nums,tmp,ans,target);
        return ans;
    }
};
