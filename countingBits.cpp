class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0) return {0};
        if (num == 1) return {0, 1};
        vector<int> bits(num + 1);
        bits[0] = 0;
        bits[1] = 1;
        for (int i = 2; i <= num; ++i) {
            bits[i] = (i % 2 != 0) + bits[i >> 1];
        }
        return bits;
    }
};
