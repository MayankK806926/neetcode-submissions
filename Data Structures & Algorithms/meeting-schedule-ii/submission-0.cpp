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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> starts,end;
        for(int i=0;i<n;++i){
            starts.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(starts.begin(),starts.end());
        sort(end.begin(),end.end());

        // for(auto& it:starts) cout << it << " ";
        // cout<<endl;
        // for(auto& it:end) cout << it << " ";
        // cout<<endl;

        int i=0,j=0;
        int cnt = 0;
        while(i<n && j<n){
            if(starts[i] < end[j]) i++;
            else j++;

            cnt = max(cnt,abs(j-i));
        }

        return cnt;
    }
};
