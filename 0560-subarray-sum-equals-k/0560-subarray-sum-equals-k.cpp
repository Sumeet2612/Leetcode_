class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int n= nums.size();
        int res = 0;
        unordered_map<int,int> freq;
        freq[0] = 1;
        for (int i=0; i<n; i++){
            
            sum = sum + nums[i];
            int q = sum-k; 
            int f = freq[q];
            res += freq[q] ;
            freq[sum]++ ;

        }
        
        return res ;
    }
};