class Solution {
public:
    bool isPowerOfTwo(int n) {
        int tmp = 1;
        while (tmp < n) {
            if (n & tmp)
                return false;
            tmp <<= 1;
        }
        return tmp == n;
    }
};