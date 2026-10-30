class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t num = 0;
        for(int i=0;i<32;++i){
            int ind = 31 - i;
            if((n & (1 << i))){
                num |= (1 << ind);
            }
        }
        return num;
    }
};
