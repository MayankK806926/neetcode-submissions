class Solution {
public:
    void rec(int ind,vector<int>& nums,vector<int> tmp,vector<vector<int>>& ans){
        if(ind == nums.size()){
            ans.push_back(tmp);
            return;
        }

        rec(ind+1,nums,tmp,ans);
        tmp.push_back(nums[ind]);
        rec(ind+1,nums,tmp,ans);
        tmp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> tmp;
        rec(0,nums,tmp,ans);
        return ans;
    }
};
