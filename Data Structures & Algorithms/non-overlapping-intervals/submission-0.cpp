class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int end = intervals[0][1];
        int cnt = 0;
        // for(auto& it:intervals){
        //     for(int& i:it) cout << i << " ";
        //     cout<<endl;
        // }

        for(int i=1;i<n;++i){
            if(intervals[i][0] < end){
                end = min(end,intervals[i][1]);
                cnt++;
            }else{
                end = intervals[i][1];
            }
        }
        return cnt;
    }
};
