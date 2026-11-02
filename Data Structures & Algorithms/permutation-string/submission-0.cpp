class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        if(n > m) return false;

        vector<int> s1hsh(26,0);
        vector<int> windowhsh(26,0);

        for(int i=0;i<n;++i){
            s1hsh[s1[i]-'a']++;
            windowhsh[s2[i]-'a']++;
        }

        if(s1hsh == windowhsh) return true;

        for(int i=n;i<m;++i){
            windowhsh[s2[i]-'a']++;
            windowhsh[s2[i-n]-'a']--;
            if(s1hsh == windowhsh) return true;
        }

        return false;
    }
};
