class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len, center;
        bool oddCenter;
        int answer = -1;
        while (1) {
            len = nums.size();
            oddCenter = (len % 4 == 3);
            center = len / 2;
            int centerVal = nums[center];
            bool side = false;
            if (len == 1) {
                answer = nums[0];
                break;
            }
            if (center == 0) {
                if (nums[center + 1] != centerVal) {
                    answer = centerVal;
                    break;
                }
            } else if (center == len - 1) {
                if (nums[center - 1] != centerVal) {
                    answer = centerVal;
                    break;
                }
            } else {
                if (nums[center - 1] != centerVal && nums[center + 1] != centerVal) {
                    answer = centerVal;
                    break;
                }
            }
            side = oddCenter ? (nums[center - 1] == centerVal) : (nums[center + 1] == centerVal);
            if (side) {
                nums.erase(nums.begin(), nums.begin() + center + oddCenter);
            } else {
                nums.erase(nums.begin() + center + !oddCenter, nums.end());
            }
        }
        return answer;
    }
};
