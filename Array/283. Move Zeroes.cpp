class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int last = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                int temp = nums[last];
                nums[last] = nums[i];
                nums[i] = temp;
                last++;
            }
        }
    }
};

// Two pointers: swap each non-zero element to the front (last pointer), pushing zeroes to the back.
// O(n) time, O(1) space.