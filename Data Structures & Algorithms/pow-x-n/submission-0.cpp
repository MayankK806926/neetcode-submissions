class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        bool neg = (N < 0);
        N = abs(N);

        double ans = 1.0;
        double curr = x;

        while(N > 0){
            if(N % 2) ans *= curr;
            curr *= curr;
            N/=2;
        }

        if(neg) return 1 / ans;
        return ans;
    }
};
