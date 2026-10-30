class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        unordered_map<int,bool> hsh;

        while(n != 1){
            int num = n;
            int val = 0;
            while(num){
                val += (num % 10) * (num % 10);
                num /= 10;
            }
            if(hsh.find(val) == hsh.end()){
                hsh[val] = true;
            }else return false;

            n = val;
        }

        return true;
    }
};
