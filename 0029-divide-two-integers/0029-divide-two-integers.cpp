class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;
        int sign = 1;
        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
            sign = 0;
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1)))
                cnt++;

            ans += (1LL << cnt);
            n -= (d << (cnt));
        }

        if (ans == (1LL << 31) && !sign) {
            return INT_MAX;
        } else if (ans == (1LL << 31) && sign) {
            return INT_MIN;
        }
        return !sign ? ans : -1 * ans;
    }
};