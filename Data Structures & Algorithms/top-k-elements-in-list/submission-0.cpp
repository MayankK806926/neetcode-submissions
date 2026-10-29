class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> hsh;
        for(int i:nums){
            hsh[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        for(auto& it:hsh){
            if(pq.size() < k) pq.push({it.second,it.first});
            else{
                if(pq.top().first < it.second){
                    pq.pop();
                    pq.push({it.second,it.first});
                }
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
