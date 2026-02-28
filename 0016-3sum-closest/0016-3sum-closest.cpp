class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());

        int left , right ; 

        int n = nums.size();
        int diff ;
        int max_diff = INT_MAX; 
        int ressum = 0 ;

        for (int i = 0; i < n-2; i++){
            left = i+1; right = n-1;
            

            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);

                if (diff < max_diff){
                    max_diff = diff ;
                    ressum = sum ;
                }
                
                if (sum < target)left ++;
                
                else if (sum > target) right --;

                else return sum ; 
            }
        }
        return ressum ; 
    }
};