class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int end = intervals[0][1];
        int start = intervals[0][0];
        vector<vector<int>> ans;

        for(int i=1;i<n;++i){
            if(intervals[i][0] <= end){
                end = max(end,intervals[i][1]);
            }else{
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start,end});

        return ans;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};
