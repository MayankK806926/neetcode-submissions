class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0;
        int prod = 1;
        for(int i=0;i<n;++i){
            if(nums[i] == 0) cnt0++;
            else prod *= nums[i];
        }
        if(cnt0 > 1) return vector<int>(n,0);
        else{
            vector<int> ans(n,0);
            if(cnt0 == 1){
                for(int i=0;i<n;++i){
                    if(nums[i] == 0){
                        ans[i] = prod;
                        break;
                    }
                }
            }else{
                for(int i=0;i<n;++i){
                    ans[i] = prod / nums[i];
                }
            }
            return ans;
        }
    }
};