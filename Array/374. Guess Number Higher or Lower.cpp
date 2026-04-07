/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long left = 1, right = n;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            int res = guess(mid);

            if (res == 0) return mid;
            else if (res == 1) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
};

// Standard binary search: use guess(mid) API to narrow the range each iteration.
// long long prevents overflow when computing mid. O(log n) time, O(1) space.