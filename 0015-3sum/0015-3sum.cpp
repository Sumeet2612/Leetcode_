class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> diary ;
        int sum = 0; int size = nums.size();
        sort(nums.begin() , nums.end());

        for(int i=0; i<size-2; i++){

            int left = i+1; int right = size-1 ;

            if(i>0 && nums[i] == nums[i-1]) continue ;

            while(left < right){
                sum = nums[i]+nums[left] + nums[right] ;

                if(sum == 0){
                    res.push_back({nums[i] , nums[left] , nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right+1]){
                        right --;
                    }
                }
                
                else if(sum > 0){
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return res;


        
    }
};