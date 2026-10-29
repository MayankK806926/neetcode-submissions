class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> hsh(26,0);
        for(auto& it:s){
            hsh[it-'a']++;
        };
        for(auto& it:t){
            hsh[it-'a']--;
        }
        
        return (hsh == vector<int>(26,0));
    }
};
