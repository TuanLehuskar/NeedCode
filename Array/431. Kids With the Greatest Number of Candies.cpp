class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxVal = 0;

        for (auto e : candies) {
            maxVal = max(maxVal, e);
        }
        int length = candies.size();
        vector<bool> res(length, false);

        for(int i = 0; i < length; ++i) {
            if (candies[i] + extraCandies >= maxVal) {
                res[i] = true;
            }
        }
        return res;
    }
};

// Find current max, then check each kid: candies[i] + extraCandies >= max → true.
// O(n) time, O(1) space (excluding output).