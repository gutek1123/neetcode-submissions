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
        int left = 1;
        int right = std::numeric_limits<int>::max();

        while (left <= right) {
            int middle = left + (right - left) / 2;

            int guessedResponse = guess(middle);

            if (guessedResponse == 0) {
                return middle;
            } else if (guessedResponse == -1) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
    }
};