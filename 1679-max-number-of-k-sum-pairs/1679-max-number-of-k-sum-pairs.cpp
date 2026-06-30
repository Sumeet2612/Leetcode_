class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = n-1; 
        int sum = 0; 
        int count = 0;
        sort(nums.begin() , nums.end());

        while (left < right){
            sum = nums[left] + nums[right];

            if (sum == k){
                count++;
                right --;
                left ++ ;
            }

            else if (sum < k){
                left++;
            }
            else {
                right--;
            }

        }
        return count  ;
        
    }
};