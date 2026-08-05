class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        unordered_map<int , int> freq ;
        int extra = 0;

        for (int i=0; i<nums.size(); i++){
            freq[nums[i]] ++ ;
        }

        for (int j=0; j<nums.size(); j++){
            if (freq[nums[j]] > 1 ){
                extra = nums[j] ;
            }
            else {
                continue ;
            }
        }

        return extra ;

        
    }
};