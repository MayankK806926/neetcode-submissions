class Solution {
public:
    vector<int> func(string s){
        vector<int> num;
        for(int i=s.size()-1,ind = 0;i>=0;--i,ind++){
            num.push_back(s[i]-'0');
        }

        return num;
    }

    string multiply(string num1, string num2) {
        vector<int> a = func(num1);
        vector<int> b = func(num2);

        vector<int> ans(500);
        int ind = 0;
        int mx = 0;
        for(int i=0;i<a.size();++i){
            int carry = 0;
            int x = a[i];
            int o = ind;
            for(int j=0;j<b.size();++j,++o){
                int val = b[j] * x + carry + ans[o];
                ans[o] = val % 10;
                carry = (val / 10);
            }

            while(carry){
                ans[o] = carry % 10;
                carry/=10;
                o++;
            }
            mx = max(o,mx);
            ind++;
        }

        string res = "";
        for(int i=0;i<mx;++i){
            res += ('0' + ans[i]);
        }
        while (res.size() > 1 && res.back() == '0') {
            res.pop_back();
        }

        reverse(res.begin(),res.end());

        return res;
    }
};
