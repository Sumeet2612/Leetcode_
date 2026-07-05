class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        for (int x : nums) total += x;
        int r = total % p;
        
        if (r == 0) return 0;
        
        unordered_map<long long, int> lastIndex;
        lastIndex[0] = -1;
        
        long long prefix = 0;
        int ans = n;
        
        for (int j = 0; j < n; j++) {
            prefix = (prefix + nums[j]) % p;
            long long need = ((prefix - r) % p + p) % p;
            
            if (lastIndex.count(need)) {
                ans = min(ans, j - lastIndex[need]);
            }
            
            lastIndex[prefix] = j;
        }
        
        return ans == n ? -1 : ans;
    }
};