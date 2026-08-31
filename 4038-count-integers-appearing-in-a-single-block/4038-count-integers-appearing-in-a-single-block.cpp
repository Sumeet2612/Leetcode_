class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        bool seen[101] = {};
        bool invalid[101] = {};

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            // If previous element is different,
            // we're starting a new block of x.
            if (i == 0 || nums[i] != nums[i - 1]) {
                if (seen[x]) {
                    invalid[x] = true;
                }

                seen[x] = true;
            }
        }

        int ans = 0;

        for (int x = 1; x <= 100; x++) {
            if (seen[x] && !invalid[x]) {
                ans++;
            }
        }

        return ans;
    }
};