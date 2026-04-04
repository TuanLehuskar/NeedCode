class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int temp = 0;
        int m = flowerbed.size();
        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 0) {

                bool prev = (i == 0 || flowerbed[i - 1] == 0);
                bool next = (i == m - 1 || flowerbed[i + 1] == 0);

                if (prev && next) {
                    flowerbed[i] = 1;
                    n--;
                    if (n == 0) return true;
                } 
            }
        }
        return n <= 0;
    }
};

// Greedy: place a flower at each empty spot where both neighbors are also empty, decrement n.
// O(m) time, O(1) space.