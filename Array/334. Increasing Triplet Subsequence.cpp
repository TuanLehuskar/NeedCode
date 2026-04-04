class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (auto num : nums) {
            if (num <= first) first = num;
            else if (num <= second) second = num;
            else return true;
        }
        return false;
    }
};

// Track the two smallest values seen so far (first, second); if a number exceeds both, triplet exists.
// O(n) time, O(1) space.