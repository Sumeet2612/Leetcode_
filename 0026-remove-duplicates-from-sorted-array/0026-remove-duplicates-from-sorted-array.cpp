class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        int unique = 1;

        while (j<n){
            if (nums[i]==nums[j]){
                j++;
            }
            else if (nums[i] != nums[j]){
                swap(nums[i+1] , nums[j]);
                unique++;
                i++;
                j++;
            }
        }

        return unique ;
        
    }
};