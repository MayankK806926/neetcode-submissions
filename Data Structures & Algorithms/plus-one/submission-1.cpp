class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int n = digits.size();
        int carry = 0;
        digits[0] += 1;
        if(digits[0] < 10){
            reverse(digits.begin(),digits.end());
            
            return digits;
        }else{
            carry = digits[0] / 10;
            digits[0] %= 10;
            for(int i=1;i<n;++i){
                digits[i] += carry;
                if(digits[i] < 10){
                    carry = 0;
                    break;
                }
                else{
                    carry = digits[i] / 10;
                    digits[i] %= 10;
                }
            }
            if(carry) digits.push_back(carry);
            reverse(digits.begin(),digits.end());
            return digits;
        }
    }
};
