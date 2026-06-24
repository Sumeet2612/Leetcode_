class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestEnd = 0;
        int ans = nums[0] ;
        int n = nums.size();

        for (int i=0; i<n; i++){
            int v1 = bestEnd + nums[i] ;
            int v2 = nums[i];
            bestEnd = max(v1 , v2);
            ans = max(ans , bestEnd);
        }
        return ans ;
    }
};