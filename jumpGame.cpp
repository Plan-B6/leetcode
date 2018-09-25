class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int pos = size - 1;
        for (int i = size - 2; i >= 0; --i) {
            if (i + nums[i] >= pos) pos = i;
        }
        return pos <= 0;
    }
};
