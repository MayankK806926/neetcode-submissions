class Solution {
public:
    string minWindow(string s, string t) {
        int cntT = 0;
        vector<int> hshT(256,0);
        for(char c:t){
            if(hshT[c] == 0) cntT++;
            hshT[c]++;
        }

        int l = 0,r = 0;
        int ans = INT_MAX;
        int startIdx = 0;
        int n = s.size();
        int cntS = 0;
        vector<int> hshS(256,0);
        while(r < n){
            hshS[s[r]]++;
            if(hshT[s[r]]  && hshS[s[r]] == hshT[s[r]]) cntS++;

            if(cntT == cntS){
                while(l < r && cntT == cntS){
                    hshS[s[l]]--;
                    if(hshT[s[l]] && hshS[s[l]] < hshT[s[l]]){
                        hshS[s[l]]++;
                        break;
                    }
                    l++;
                }

                if(ans > (r-l+1)){
                    ans = r-l+1;
                    startIdx = l;
                }
            }

            r++;
        }
        if(ans == INT_MAX) return "";
        return s.substr(startIdx,ans);
    }
};
