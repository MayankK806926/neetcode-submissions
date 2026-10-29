class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> hsh;
        for(int i=0;i<n;++i){
            hsh[nums[i]]++;
            if(hsh[nums[i]] > 1) return true;
        }
        return false;
    }
};