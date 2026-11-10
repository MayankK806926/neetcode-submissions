class Solution {
public:
    int func(string s){
        int num = 0;
        bool neg = false;
        for(int i = 0;i<s.size();++i){
            if(i == 0){
                if(s[i] == '+') continue;
                else if(s[i] == '-'){
                    neg = true;continue;
                }
            }
            int x = s[i] - '0';
            num = num * 10 + x;
        }

        if(neg) return -1 * num;
        return num;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();

        for(int i=0;i<n;++i){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                int num = func(tokens[i]);
                st.push(num);
            }else{
                int x = st.top();st.pop();
                int y = st.top();st.pop();
                int val = 0;
                if(tokens[i] == "+"){
                    val = x + y;
                }else if(tokens[i] == "-") val = y - x;
                else if(tokens[i] == "*") val = x * y;
                else val = y / x;
                // cout << val << endl;
                st.push(val);
            }
        }

        return st.top();
    }
};
