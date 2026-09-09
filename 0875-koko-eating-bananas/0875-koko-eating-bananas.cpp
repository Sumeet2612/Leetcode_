class Solution {
public:

    long long fun(vector<int>& piles, int n, int speed) {
        long long h = 0;

        for (int i = 0; i < n; i++) {
            h += piles[i] / speed;

            if (piles[i] % speed) {
                h++;
            }
        }

        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();

        long long low = 1;
        long long high = INT_MIN;

        // Find maximum pile
        for (int i = 0; i < n; i++) {
            if (piles[i] > high) {
                high = piles[i];
            }
        }

        int res = -1;

        while (low <= high) {

            // Safe version of (low + high) / 2
            long long guess = ((long long)low + high) / 2;

            long long hour = fun(piles, n, guess);

            if (hour > h) {
                low = guess + 1;
            }
            else {
                res = guess;
                high = guess - 1;
            }
        }

        return res;
    }
};