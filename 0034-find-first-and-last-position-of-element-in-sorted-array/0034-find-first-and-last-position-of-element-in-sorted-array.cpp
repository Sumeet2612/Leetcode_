class Solution {
public:

    int low (vector<int> &nums , int target){
        
        int n = nums.size();
        int low = 0; int high = n-1;
        int res = -1 ;

        while(high >= low){

            int guess = (low + high) / 2;

            if (nums[guess] > target){
                high = guess - 1;
            }
            else if (nums[guess] < target){
                low = guess + 1;
            }
            else {
                res = guess;
                high = guess-1;
            }
        }
        return res;

    }
    int high(vector<int> &nums , int target){
        
        int n = nums.size();
        int low = 0; int high = n-1;
        int res = -1 ;

        while(high >= low){

            int guess = (low + high) / 2;

            if (nums[guess] > target){
                high = guess - 1;
            }
            else if (nums[guess] < target){
                low = guess + 1;
            }
            else {
                res = guess;
                low = guess+1;
            }
        }
        return res;

    }

    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> resarr ;

        int left = low(nums , target);
        int right = high(nums , target);

        resarr.push_back(left);
        resarr.push_back(right);

        return resarr;
        
    }
};