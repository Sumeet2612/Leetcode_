class Solution {
public:

    int maxSum (vector<int>& nums){
        int n = nums.size();
        int bestEndMax = nums[0];
        int maxRes = nums[0];

        for (int i=1; i<n; i++){
            bestEndMax = max(nums[i] , bestEndMax + nums[i]);
            maxRes = max(maxRes , bestEndMax);
        }
        return maxRes;
    }
    int minSum (vector<int>& nums){
        int n = nums.size();
        int bestEndMin = nums[0];
        int minRes = nums[0];

        for (int i=1; i<n; i++){
            int v1 = bestEndMin + nums[i];
            int v2 = nums [i];
            bestEndMin = min(nums[i] , bestEndMin + nums[i]);
            minRes = min(minRes , bestEndMin);
        }
        return minRes;
    }


    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;

        for (int i=0; i<nums.size(); i++){
            totalSum = totalSum + nums[i];
        }
        int minsum = minSum(nums);
        int maxsum = maxSum(nums);

        if (totalSum == minsum){
            return maxsum;
        }

        int maxres = totalSum - minsum ;

        return max (maxres , maxsum) ;
    }

    
};