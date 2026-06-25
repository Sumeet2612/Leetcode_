class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxEnd = nums[0];
        int minEnd = nums[0];
        int ans = nums[0] ;

        for (int i = 1; i < n; i++){
            int v1 = nums[i];
            int v2 = nums[i] * maxEnd;
            int v3 = nums[i] * minEnd;

            maxEnd = max(v1 , max(v2 , v3));
            minEnd = min(v1 , min(v2 , v3));

            ans = max( ans , max(maxEnd , minEnd));
        }
        return ans ;
        
    }
};