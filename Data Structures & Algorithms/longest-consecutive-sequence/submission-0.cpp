class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,bool> hsh;
        unordered_map<int,int> cnting;

        for(int i=0;i<n;++i){
            hsh[nums[i]] = true;
            cnting[nums[i]] = 1;
        }
        int ans = 0;
        for(int i=0;i<n;++i){
            int cnt = 1;
            int num = nums[i];
            while(hsh[num+1]){
                cnt += cnting[num+1];
                if(cnting[num+1] > 1) break;
                num++;
            }
            num = nums[i];
            cnting[num] = cnt;
            while(cnting[num+1] == 1){
                --cnt;
                cnting[num+1] = cnt;
                num++;
            }

            ans = max(ans,cnting[nums[i]]);
        }
        // for(auto& it:cnting){
        //     cout<< it.first << " " << it.second << "\n";
        // }

        return ans;
    }
};
