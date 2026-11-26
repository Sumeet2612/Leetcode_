class Solution {
public:
    int countDominantElements(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) return 1 ;

        int dom = 0;
        double avg ;

        for (int i=0; i<n; i++){
            if(i==0){
                if(nums[i] >= nums[i+1]) dom++ ;
            }
            else if (i == n - 1){
                if(nums[i] >= nums[n-2]) dom++ ;
            }
            else {
                float sum = nums[i-1] + nums[i+1];

                if(nums[i] * 2 >= sum ){
                    dom++;
                } 
            }
        }

        return dom;
    }
};