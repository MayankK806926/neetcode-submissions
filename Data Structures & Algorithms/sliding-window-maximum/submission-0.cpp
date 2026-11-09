class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i=0;i<n;++i){
            if(i < k) pq.push({nums[i],i});
            else{
                int left = i-k+1;
                pq.push({nums[i],i});
                while(!pq.empty()){
                    if(pq.top().second < left) pq.pop();
                    else break;
                }
            }

            if(i >= k-1) ans.push_back(pq.top().first);
        }

        return ans;
    }
};
