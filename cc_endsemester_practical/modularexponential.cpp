class Solution {
public:
    int powMod(int x, int n, int M) {
        int result = 1;
        int base = x % M;

        while (n > 0) {
            if (n & 1) {
                result = (result * base) % M;
            }
            base = (base * base) % M;
            n >>= 1;
        }

        return (int)result;
    }
};