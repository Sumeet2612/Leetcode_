class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int prod = 0;
        int maxprod = INT_MIN;
        for (int i=0; i<n; i++){
            for(int j=i+1; j<n;j++){
                prod = (nums[i] - 1) * (nums[j] - 1);
                if (prod > maxprod){
                    maxprod = prod;
                }

            }
        }

        return maxprod;
        
    }
};