class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(n);
        int j = 0;

        for (int i=0; i<n; i++){
            if (nums[i] != 0){
                res[j] = nums[i];
                j++ ;
            }
        }
        while (j<=n){
            res.push_back(0);
            j++ ;
        }
        for (int i=0; i<n; i++){
            nums[i] = res[i];
        }
        
    }
};