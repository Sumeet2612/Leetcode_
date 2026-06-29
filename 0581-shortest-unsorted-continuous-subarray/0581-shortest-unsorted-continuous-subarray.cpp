class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxSoFar = nums[0];
        int right = -1; 

        for (int i = 1; i < n; i++) {
            if (nums[i] < maxSoFar) {
                right = i; 
            } else {
                maxSoFar = nums[i];
            }
        }


        int minSoFar = nums[n - 1];
        int left = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > minSoFar) {
                left = i; 
            } else {
                minSoFar = nums[i];
            }
        }

        if (right == -1) return 0;

        return right - left + 1;
    }
};