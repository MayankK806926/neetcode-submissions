class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;++i){
            if(i > 0){
                while(i < n-2 && nums[i] == nums[i-1]) i++;
            }
            int tar = -nums[i];
            int j = i+1,k = n-1;
            while(j < k){
                if(nums[j] + nums[k] == tar){
                    vector<int> tmp = {nums[i],nums[j],nums[k]};
                    sort(tmp.begin(),tmp.end());
                    ans.insert(tmp);
                    j++;k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }else if(nums[j] + nums[k] > tar) k--;
                else j++;
            }

        }
        vector<vector<int>> res;
        for(auto& it:ans) res.push_back(it);

        return res;
    }
};
