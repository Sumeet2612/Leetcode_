class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();
        int sum = 0;
        unordered_map<int,int> freq;
        int rem = 0;
        int res = 0; 

        freq[0] = 1;
        for (int i=0; i<n; i++){
            sum = sum + nums[i];
            rem = sum % k ;
            if (rem < 0){
                rem = rem + k;
            }
            res = res + freq[rem];
            freq[rem] ++ ;
            
        }

        return res ;
        
    }
};