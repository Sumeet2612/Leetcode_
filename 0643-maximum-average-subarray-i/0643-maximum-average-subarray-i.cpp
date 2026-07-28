class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();
        double sum = 0 ;
        double avg ;


        for (int i=0; i<k; i++){
            sum = sum + nums[i];
        }
        avg = sum / k ;
        double maxavg = avg;
        for (int i=k; i<n; i++){
            sum = sum - nums[i-k];
            sum = sum + nums[i];

            double currentavg  = sum / k ;
            maxavg = max(currentavg , maxavg);
        }

        double finalavg = max(maxavg , avg);

        return maxavg;
        
    }
};