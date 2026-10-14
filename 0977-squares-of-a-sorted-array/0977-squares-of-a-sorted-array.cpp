
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n);

        int left = 0;
        int right = n - 1;
        int index = n - 1;

        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                res[index] = leftSquare;
                left++;
            }
            else {
                res[index] = rightSquare;
                right--;
            }

            index--;
        }

        return res;
    }
};

