class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int low = 0 ; int high = 0 ;
        int size = 0 ; int len = 0; 
        int sum  = 0; 
        int res = INT_MAX ;
        while (high < n){
            sum = sum + nums[high];

            while (target <= sum){
                len = high - low + 1 ;
                res = min(len , res);
                sum = sum - nums[low];
                low ++ ;
            }
            high++ ;
        }

        if (res == INT_MAX) return 0;

        return res;
    }
};