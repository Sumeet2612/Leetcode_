class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort (nums.begin() , nums.end());

        int n = nums.size();
        vector <long long> prefix (n+1 , 0);

        for (int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }

        int left = 0;
        int ans = 1;

        for (int right = 0; right <n; right++){

        long long wSum = prefix[right + 1] - prefix[left];

        long long cost = 1LL*nums[right]*(right - left +1) - wSum;

        while (cost > k){
            left ++;
            wSum = prefix[right +1] - prefix[left];

            cost = 1LL * nums[right] * (right - left + 1) -wSum;

        }
        ans = max(ans , right-left +1 );
        }

        return ans;

        
    }

    
};