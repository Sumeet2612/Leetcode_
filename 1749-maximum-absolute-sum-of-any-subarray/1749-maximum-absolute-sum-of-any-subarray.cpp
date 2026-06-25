class Solution {
public:
    int maxSum(vector<int>& nums){
        int n = nums.size();
        int bestEnd = nums[0];
        int result = nums[0]; 

        for (int i=1; i<n; i++){
            int v1 = nums[i];
            int v2 = bestEnd + nums[i];
            bestEnd = max( v1 , v2);
            result = max(bestEnd , result);
        }

        return abs(result);
    }
    int minSum(vector<int>& nums){
        int n = nums.size();
        int bestEnd = nums[0];
        int result = nums[0]; 

        for (int i=1; i<n; i++){
            int v1 = nums[i];
            int v2 = bestEnd + nums[i];
            bestEnd = min( v1 , v2);
            result = min(bestEnd , result);
        }
        return abs(result);
    }


    int maxAbsoluteSum(vector<int>& nums) {

        int maxsum = maxSum(nums);
        int minsum = minSum(nums);

        int res = max (maxsum , minsum);

        return res ;
        
    }
};