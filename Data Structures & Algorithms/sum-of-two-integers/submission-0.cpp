class Solution {
public:
    int getSum(int a, int b) {
        for(int i=0;i<32;++i){
            if((b & (1 << i))){
                cout << i << " ";
                int j = i;
                while(j < 32){
                    if((a & (1 << j))){
                        a ^= (1 << j);
                        j++;
                    }else{
                        a ^= (1 << j);
                        break;
                    }
                }
            }
        }

        return a;
    }
};
