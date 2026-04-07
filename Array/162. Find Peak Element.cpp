class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

// Binary search: if nums[mid] > nums[mid+1], peak is on the left half (include mid); otherwise on the right.
// Guaranteed to converge because boundaries are treated as -infinity. O(log n) time, O(1) space.