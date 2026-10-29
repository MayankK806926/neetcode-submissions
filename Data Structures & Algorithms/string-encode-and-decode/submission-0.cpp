class Solution {
public:
    string encode(vector<string>& strs) {
        string ans = "";
        for(const string& s:strs){
            ans += to_string(s.size()) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int n = s.size();
        int i = 0;
        while(i < n){
            int j = i;
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i,j-i));
            res.push_back(s.substr(j+1,len));
            i = j + 1 + len;
        }

        return res;
    }
};
