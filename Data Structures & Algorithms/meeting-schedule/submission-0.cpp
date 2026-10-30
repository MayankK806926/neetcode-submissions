/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n <= 1) return true;
        vector<pair<int,int>> meetings;
        for(auto& it:intervals){
            meetings.push_back({it.end,it.start});
        }
        sort(meetings.begin(),meetings.end());

        int e = meetings[0].first;

        for(int i=1;i<n;++i){
            if(meetings[i].second >= e){
                e = meetings[i].first;
            }else return false;
        }

        return true;
    }
};
